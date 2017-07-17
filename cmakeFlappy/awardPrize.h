#ifndef AWARPRICE
#define AWARPRICE

#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include "productsmanager.h"
#include <QList>
#include <QMessageBox>
#include "gameelement.h"



enum Products{PRODUCTO_1,
              PRODUCTO_2,
              PRODUCTO_3,
              PRODUCTO_4,
              PRODUCTO_5,
              PRODUCTO_6,
              PRODUCTO_7,
              PRODUCTO_8,
              PRODUCTO_9,
              PRODUCTO_10,
             };

class awardPrize : public QMainWindow{
    Q_OBJECT

public:
    awardPrize(QWidget *parent= 0);
    void init();
    void deliverPrize(Products product);
    void resizeEvent(QResizeEvent *);
    void enablePrizes(int);
    ProductsManager *getManager();

public slots:
    void displayInfo();

private:
    ProductsManager *manager;
    QList<QPushButton *> buttonList;
    QMessageBox *a;
    int orden[10]= {0, 8, 1, 9, 2, 3, 4, 5, 6, 7};

signals:
    void selectedPrize();

};
#endif
