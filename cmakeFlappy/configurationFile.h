#ifndef CONFIGURATIONFILE
#define CONFIGURATIONFILE

#include <QFile>
#include <QString>
#include <QVariant>
#include <QByteArray>
#include <QIODevice>


class configurationFile : public QFile{
    Q_OBJECT

public:
    configurationFile(const QString &, QObject *parent= 0);
    double readLifePrice();
    double readInityalVelocity();
    QVariant readKey(const QString &key);

    QByteArray data;
};



#endif
