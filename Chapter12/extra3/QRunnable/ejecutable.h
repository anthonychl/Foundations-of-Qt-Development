#ifndef EJECUTABLE_H
#define EJECUTABLE_H

#include <QRunnable>
#include <QDebug>

class Ejecutable : public QRunnable
{
public:
    Ejecutable(unsigned short ID);
    unsigned short id;
protected:
    virtual void run();

};

#endif // EJECUTABLE_H
