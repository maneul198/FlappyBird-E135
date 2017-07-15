#include "awardPrize.h"
#include <QKeyEvent>
#include <QCoreApplication>
#include <QApplication>


awardPrize::awardPrize(QWidget *parent):
    QMainWindow(parent)
{
    manager = new ProductsManager();
    connect(manager, SIGNAL(delivered(Product*)), this, SLOT(displayInfo()));
    init();
}

void awardPrize::init(){
    resize(540, 760);
    setStyleSheet("background-image: url(" + GameElement::url + "/image/bg_day.png)");

    for(int i= 0; i < 9; i++){
        QPushButton * button = new QPushButton(this);
        button->setStyleSheet("QPushButton{border-image:url("
                              + GameElement::url + "image/products/goproCamer.jpg);"
                                                   "} QPushButton:focus{margin: 2px 2px 2px 2px;}"
                                                   "QPushButton{margin: 15px 15px 15px 15px}");

        double BUTTON_WIDTH = width() / 4;
        double BUTTON_HEIGH = height() / 4;
        double HORIZONTAL_BUTTON_SEPARATION = BUTTON_WIDTH / 4;
        double VERTICAL_BUTTON_SEPARATION = BUTTON_HEIGH / 4;

        button->setGeometry(QRect(BUTTON_WIDTH * (i % 3) + HORIZONTAL_BUTTON_SEPARATION * ((i % 3) + 1),
                                            BUTTON_HEIGH * (i / 3) + VERTICAL_BUTTON_SEPARATION * ((i / 3) + 1),
                                            BUTTON_WIDTH, BUTTON_HEIGH));

        button->setEnabled(false);
        buttonList.append(button);

        connect(button, &QPushButton::pressed, this, [=](){
            manager->turnHook(i);
            //close();
            emit selectedPrize();
        });

    }

    buttonList.at(8)->setStyleSheet("QPushButton{border-image:url("
                                    + GameElement::url + "image/products/gopro.jpg);"
                                    "} QPushButton:focus{margin: 2px 2px 2px 2px;}"
                                    "QPushButton{margin: 15px 15px 15px 15px}");

    buttonList.at(4)->setStyleSheet("QPushButton{border-image:url("
                                    + GameElement::url + "image/products/papas.jpg);"
                                    "} QPushButton:focus{margin: 2px 2px 2px 2px;}"
                                    "QPushButton{margin: 15px 15px 15px 15px}");
}

void awardPrize::resizeEvent(QResizeEvent *){
    double BUTTON_WIDTH = width() / 4;
    double BUTTON_HEIGH = height() / 4;
    double HORIZONTAL_BUTTON_SEPARATION = BUTTON_WIDTH / 4;
    double VERTICAL_BUTTON_SEPARATION = BUTTON_HEIGH / 4;

    for(int c= 0; c < 9; c++){
        buttonList.at(c)->setGeometry(QRect(BUTTON_WIDTH * (c % 3) + HORIZONTAL_BUTTON_SEPARATION * ((c % 3) + 1),
                                            BUTTON_HEIGH * (c / 3) + VERTICAL_BUTTON_SEPARATION * ((c / 3) + 1),
                                            BUTTON_WIDTH, BUTTON_HEIGH));
    }
}

void awardPrize::enablePrizes(int num){
    for(int i= 0; i < 9; i++){
        buttonList.at(i)->setEnabled(false);
    }

    for(int i= 9 - num; i < 9 -num + 3; i++){
        buttonList.at(i)->setEnabled(true);
    }
}

ProductsManager *awardPrize::getManager()
{
   return manager;
}

void awardPrize::displayInfo()
{
    //soundSwooshing->play();
    a = new QMessageBox("FELICIDADES", "FELICIDADES RECOJA SU PREMIO",
                                     QMessageBox::NoIcon, QMessageBox::NoButton,
                                     QMessageBox::NoButton, QMessageBox::NoButton, this);
    a->show();

    QTimer::singleShot(5000, this, [=](){
        a->close();
        close();
    });
}
