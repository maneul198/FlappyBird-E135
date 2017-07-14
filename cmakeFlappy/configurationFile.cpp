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
