#ifndef PRODUCTSMANAGER_H
#define PRODUCTSMANAGER_H

#include <string>
#include <QObject>
#include <QList>
#include <atomic>
#include <QQmlListProperty>
#include <QQmlParserStatus>
#include <QSettings>
#include <QThread>

#ifdef GPIO
    #include <gpio.h>
#else
    #include <digital_ports.h>
    #include <watchioports.h>
    #include <digitalinput.h>
#endif

#include "product.h"
#include <enginesv.h>

class ProductsManager : public QObject {
    Q_OBJECT
public:
    ProductsManager(QObject *parent = 0);
    ProductsManager(DPX::Line, QObject *parent= 0);
    
    QQmlListProperty<Product> products();
    static void appendProducts(QQmlListProperty<Product> *p, Product *value);
    static int countProducts(QQmlListProperty<Product> *p);
    static Product *atProducts(QQmlListProperty<Product> *p, int index);
    static void clearProducts(QQmlListProperty<Product> *p);


    //En vista de que el sesarrollador Smith planeava usar esta clase
    // dentro de QML se crean metodos analogos pero para usar directamete
    // en c++ ya que este proyecto no usa QML

    void addProduct(Product *);
    
    Product *product(int index);
    
    
    int sensor() const;
    void setSensor(int inputpin);
    
    bool busy() const;
    
    bool enabledLights() const;
    void setEnabledLights(bool enable);
    
    int selected() const;
    
    int spinTime() const;
    void setSpinTime(int spinTime);
    
    int countHooks() const;

public slots:
    Q_INVOKABLE void turnHook(uint hook);
    Q_INVOKABLE void selectHook(uint hook);
    Q_INVOKABLE void unselectHooks();
    
signals:
    void delivered(Product *product);
    void deliveredNumberHook(uint hook);
    void started();
    void timeout(uint hook);
    void noProduct();
    void stopped();
    
    void productsChanged();
    void enabledLightsChanged();
    void selectedChanged();
    void busyChanged();
    void spinTimeChanged();
    
private:
    void turnHook();
    void stopHook();
    void setBusy(bool busy);
    void sensorChanged(bool value);
    
    EngineSV *m_engineHook {nullptr};
    DPX::DigitalInput *m_sensor {nullptr};
    
    std::atomic<bool> m_busy;
    
    // hook selected
    uint m_currentHook {0};
    int m_turnOnCounter {3};
    int m_spinTime {2400};
    
    bool m_enableLights {false};
    bool m_delivered {false};
    int orden[10]= {0, 8, 1, 9, 2, 3, 4, 5, 6, 7};
    QTimer *timer;
    
    QList<Product *> m_products;
    Product m_none;
};
#endif // PRODUCTSMANAGER_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
