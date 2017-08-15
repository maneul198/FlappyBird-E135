#include "productsmanager.h"

ProductsManager::ProductsManager(QObject *parent) :
    QObject(parent)
{
    m_engineHook = new EngineSV(0, this);


#ifdef GPIO
    m_sensor = new GPIO(sensorGPIO.toString().toStdString());
    m_sensor->export_gpio();
    m_sensor->setdir_gpio(GPIO::Direction::IN);
#else

    connect(m_engineHook, &EngineSV::engineFinished, [&](){
        //m_spinTime= 800;
        QTimer::singleShot(800, this, [=]{
            turnHook();

        });
    });

    timer= new QTimer(this);
    timer->setInterval(1000);
    timer->setSingleShot(true);

#endif
}

ProductsManager::ProductsManager(DPX::Line inputPin, QObject *parent):
    QObject(parent)
{
    m_engineHook= new EngineSV(0, this);
    setSensor(inputPin);
    connect(m_engineHook, &EngineSV::engineFinished, [&](){
        QTimer::singleShot(800, this, [=]{
            turnHook();
        });
    });
}

QQmlListProperty<Product> ProductsManager::products()
{
    return QQmlListProperty<Product>(this, nullptr
                                     , &appendProducts, &countProducts
                                     , &atProducts, &clearProducts);
}

void ProductsManager::appendProducts(QQmlListProperty<Product> *p, Product *value)
{
    auto pm = qobject_cast<ProductsManager *>(p->object);

    if (pm) {
        pm->m_products.append(value);
        emit pm->productsChanged();
    }
}

int ProductsManager::countProducts(QQmlListProperty<Product> *p)
{
    return qobject_cast<ProductsManager *>(p->object)->m_products.count();
}

Product *ProductsManager::atProducts(QQmlListProperty<Product> *p, int index)
{
    auto pm = qobject_cast<ProductsManager *>(p->object);

    if (pm && pm->m_products.count() > index)
        return pm->m_products.at(index);

    return nullptr;
}

void ProductsManager::clearProducts(QQmlListProperty<Product> *p)
{
    auto pm = qobject_cast<ProductsManager *>(p->object);

    if (pm) {
        pm->m_products.clear();
        emit pm->productsChanged();
    }
}

Product *ProductsManager::product(int index)
{
    return m_products.at(index);
}


int ProductsManager::sensor() const
{
    if (m_sensor)
        return 8 * m_sensor->port() + m_sensor->pin();

    return -1;
}

void ProductsManager::setSensor(int inputpin)
{
    QSettings config;
    int bouncetime = config.value("hooks-sensor-bouncetime", 500).toUInt();

    if (m_sensor)
        DPX::WatchDIPorts::self().unregister(*m_sensor);

    int port = DPX::DI[inputpin][DPX::GET_PORT];
    int pin = DPX::DI[inputpin][DPX::GET_PIN];
    m_sensor = DPX::WatchDIPorts::self().registerDigitalInput(port, pin, DPX::Rising, bouncetime);

    connect(m_sensor, &DPX::DigitalInput::triggered, this, &ProductsManager::sensorChanged);
}

bool ProductsManager::busy() const
{
    return m_busy.load();
}

bool ProductsManager::enabledLights() const
{
    return m_enableLights;
}

void ProductsManager::setEnabledLights(bool enable)
{
    m_enableLights = enable;
    emit enabledLightsChanged();
}

int ProductsManager::selected() const
{
    return m_currentHook;
}

int ProductsManager::spinTime() const
{
    return m_spinTime;
}

void ProductsManager::setSpinTime(int spinTime)
{
    m_spinTime = spinTime;
    emit spinTimeChanged();
}

int ProductsManager::countHooks() const
{
    return m_products.count();
}

void ProductsManager::turnHook(uint hook)
{
    if (hook >= m_products.count() && false) {
        qWarning() << "hook:" << hook << "out of range";
        return;
    }

    qDebug() << "EL PRODUCTO ES: " << m_products.at(hook)->name() << endl;
    if(m_products.at(hook)->count() == 0){
        qWarning() << "hook:" << "no products" << endl;
        emit noProduct();
        return;
    }

    // restart the counter of the max number of intents
    m_turnOnCounter = 3;
    m_currentHook = hook;
    m_spinTime= 2400;

    // ensure that the motors is off

    if (busy()) {
        m_engineHook->turnOffLights();
        m_engineHook->turnOffEngines();
    }

    setBusy(true);
    qDebug() << "hook:" << hook << "try to turn on";
    turnHook();
}

void ProductsManager::turnHook()
{
    qDebug() << m_turnOnCounter << "COUNTER" << endl;
    if (m_delivered && false) {
        m_products.at(m_currentHook)->decreaseCount();
        emit delivered(m_products.at(m_currentHook));
        setBusy(false);
    } else {
        if (m_turnOnCounter == 0) {
            //stopHook();
            emit timeout(m_currentHook);
            return;

        } else {
            --m_turnOnCounter;

            //m_enableLights= false;
            /*
            if (m_enableLights)
                m_engineHook->turnOnLight(EngineSV::li.at(m_currentHook));
                */

            try {
                m_engineHook->turnOnEngine(EngineSV::eng.at(m_currentHook), m_spinTime);

            } catch (const std::runtime_error &e) {
                qDebug() << e.what();
                emit stopped();
                return;
            }

            setBusy(false);

            //emit started();
        }
    }
}

void ProductsManager::stopHook()
{
    m_turnOnCounter = 0;
    m_delivered = false;
    qDebug() << "hook:" << m_currentHook << "trying to turn off";
    m_engineHook->turnOffEngine(EngineSV::eng[m_currentHook]);
    emit stopped();
}

void ProductsManager::setBusy(bool busy)
{
    m_busy.store(busy);
    emit busyChanged();
}

void ProductsManager::sensorChanged(bool value)
{
    if(timer->isActive()) return;

    //m_busy= true;
    if (value && m_busy) {
        m_delivered = true;
        stopHook();
    } else {
        qWarning() << "hook: The sensor was activated by mistake, or maybe was intentional";
        emit delivered(&m_none);
        emit deliveredNumberHook(m_currentHook);
        stopHook();
        m_products.at(m_currentHook)->decreaseCount();
        qDebug() << m_currentHook << "Producto" << m_products.at(m_currentHook)->name() << endl;
    }
    timer->start();
}


void ProductsManager::selectHook(uint hook)
{
    if (m_busy)
        return;

    m_engineHook->turnOffLights();
    m_engineHook->turnOnLight(EngineSV::li.at(hook));

    emit selectedChanged();
}

void ProductsManager::unselectHooks()
{
    if (m_busy || !m_enableLights)
        return;

    m_engineHook->turnOffLights();
}

void ProductsManager::addProduct(Product *product){
    m_products.append(product);
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
