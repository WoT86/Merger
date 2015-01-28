#include "imagemerger.h"

ImageMerger::ImageMerger(const QImage &first, const QImage &second, QObject *parent) :
    QObject(parent),
    firstImage(first),
    secondImage(second),
    offsetX(0),
    offsetY(0),
    channelsEnabled{true,true,true},
    busy(true),
    truncate(true)
{

    this->workerThread.start();
}

ImageMerger::ImageMerger(QObject *parent):
    QObject(parent),
    offsetX(0),
    offsetY(0),
    channelsEnabled{true,true,true},
    busy(true),
    truncate(true)
{
    this->workerThread.start();
}

ImageMerger::~ImageMerger()
{
    this->workerThread.quit();
    this->workerThread.wait();
}

void ImageMerger::setFirstImage(const QImage &img)
{
    this->firstImage = img;
}

void ImageMerger::setSecondImage(const QImage &img)
{
    this->secondImage = img;
}

void ImageMerger::setOffset(int off_x, int off_y)
{
    this->offsetX = off_x;
    this->offsetY = off_y;
}

void ImageMerger::enableTruncate(bool enable)
{
    this->truncate = enable;
}

void ImageMerger::enableChannels(Channels toEnable)
{
    if(toEnable & ALL)
    {
        this->channelsEnabled[0] = true;
        this->channelsEnabled[1] = true;
        this->channelsEnabled[2] = true;
        return;
    }

    this->channelsEnabled[0] = (toEnable & RED);
    this->channelsEnabled[1] = (toEnable & GREEN);
    this->channelsEnabled[2] = (toEnable & BLUE);
}

void ImageMerger::disableChannels(Channels toDisable)
{
    if(toDisable & ALL)
    {
        this->channelsEnabled[0] = false;
        this->channelsEnabled[1] = false;
        this->channelsEnabled[2] = false;
        return;
    }

    this->channelsEnabled[0] = !(toDisable & RED);
    this->channelsEnabled[1] = !(toDisable & GREEN);
    this->channelsEnabled[2] = !(toDisable & BLUE);
}

QString ImageMerger::channelsToMergeStr()
{
    QString str;

    str += tr("Red:") + QString(" ") + ((this->channelsEnabled[0]) ? tr("enabled") : tr("disabled")) + QString(" ");
    str += tr("Green:") + QString(" ") + ((this->channelsEnabled[0]) ? tr("enabled") : tr("disabled")) + QString(" ");
    str += tr("Blue:") + QString(" ") + ((this->channelsEnabled[0]) ? tr("enabled") : tr("disabled"));

    return str;
}

ImageMerger::Channels ImageMerger::channelsToMerge()
{
    unsigned int ch = 0x00;

    if(this->channelsEnabled[0])
        ch |= RED;

    if(this->channelsEnabled[1])
        ch |= GREEN;

    if(this->channelsEnabled[2])
        ch |= BLUE;

    if((ch & RED) && (ch & GREEN) && (ch & BLUE))
        ch = ALL;

    return ch;
}

bool ImageMerger::isBusy() const
{
    return this->busy;
}

QImage *ImageMerger::getMergeResult()
{
    return &(this->result);
}

void ImageMerger::startMerge()
{

}


MergeWorker::MergeWorker(QImage *first, QImage *second, QObject *parent):
    QObject(parent),
    firstImg(first),
    secondImg(second)
{

}

MergeWorker::~MergeWorker()
{

}

void MergeWorker::doWork(ImageMerger::Channels channels, bool truncate, int off_x, int off_y)
{
    //TODO
}
