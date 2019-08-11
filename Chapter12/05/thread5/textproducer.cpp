#include "textproducer.h"

TextProducer::TextProducer(QString t):QThread()
{
    mText = t;
}


void TextProducer::run()
{
    for( int i=0; i<mText.length(); ++i )
    {
    freeSpace.acquire();

    addtoBuffer(mText[i],i);
    //buffer[ i % bufferSize ] = mText[ i ];
    //qDebug()<<"prod "<<i<<buffer[ i % bufferSize ]; //probando q se escribe en buffer OK
    //buffer.append(mText[i]);

    if( i == mText.length()-1 )
        atEnd = true;

    availableData.release();
    }
}
