#include "ejecutable.h"

Ejecutable::Ejecutable(unsigned short ID)
{
    id=ID;
}

void Ejecutable::run()
{
    unsigned short i;
    for(i=0;i<9;i++)
       qDebug()<<id<<": "<<i;
}
