#include "textconsumer.h"

/*TextConsumer::TextConsumer()
{
}
*/

void TextConsumer::run()
{
    qDebug()<< "consumer run()";
    int i = 0;

    while( !atEnd || availableData.available() )
    {
       /* qDebug()<<"loop "<<i;
        bool trsd = availableData.tryAcquire(1);
        if(trsd)
            qDebug()<<"available" ;*/

        availableData.acquire();

        readfromBuffer(i);

        //qDebug()<< " buffer[ "<<i<<" ] " << buffer[i];

        //qDebug()<< buffer.at(i);


        i = (i+1) % bufferSize;

        freeSpace.release();
    }
}
