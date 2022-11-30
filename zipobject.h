#ifndef ZIPOBJECT_H
#define ZIPOBJECT_H

#include <QObject>
#include <QProcess>
#include <QFile>
#include <QDebug>
#include <QDir>

class zipObject : public QObject
{
    Q_OBJECT
public:
    explicit zipObject(QObject *parent = 0);
    ~zipObject();

    bool doProcess(const QString &filename,const QString &password ="");
private:
    QProcess *mp_process;
};

#endif // ZIPOBJECT_H
