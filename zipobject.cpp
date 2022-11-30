#include "zipobject.h"

zipObject::zipObject(QObject *parent) : QObject(parent)
{
    mp_process = new QProcess();

}

zipObject::~zipObject()
{
    if(mp_process)
    {
        delete mp_process;
    }
    mp_process = NULL;
}

bool zipObject::doProcess(const QString &filename, const QString &password)
{
    if(mp_process == NULL)
    {
        return false;
    }
    QStringList params;
    params.append("x");
    if(password != "")
    {
        params.append(QString("-p:%1").arg(password));
    }
    QString dirPath = QFileInfo(filename).absolutePath();
    params.append(QString("-o:%1").arg(dirPath));
    params.append(filename);


    qDebug()<<"params"<<params;
    int ret = mp_process->execute("C:/Program Files/Bandizip/Bandizip.exe", params);
    mp_process->waitForFinished();
    qDebug()<<"return :"<<ret;

    mp_process->close();

    return true;
}
