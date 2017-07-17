#include "configurationFile.h"
#include <QDebug>


configurationFile::configurationFile(const QString &name, QObject *parent):
    QFile(name, parent)
{

    open(QIODevice::ReadOnly);
    data= readAll();

    close();
}

QVariant configurationFile::readKey(const QString &key){
    QString stringKey;
    QString value;


    for(int i= 0; i < data.size(); i++){
        QByteRef cr= data[i];

        if(stringKey != key){
            if(cr != '=' && cr != '\n'){
                stringKey+= cr;
            }
            else{
                stringKey= "";
                continue;
            }
        }else{
            if(cr == '\n'){
                return value;
            }else if(cr == '='){
                continue;
            }else{
                value+= cr;
            }
        }

    }

    return QVariant(value);
}

void configurationFile::writeOnFile(QString name, QVariant value){
    QFile file(name);
    if(!file.open(QIODevice::Append)){
        qDebug() << "NOSE PUEDE ENCONTRAR EL ARCHIVO" << endl;
        return;
    }

    QTextStream out(&file);
    out << QDateTime::currentDateTime().toString(Qt::ISODate) << ": $" << value.toString() << "\n";
    file.close();
}
