#ifndef IMAGEMERGER_H
#define IMAGEMERGER_H

#include <QObject>
#include <QImage>
#include <QThread>

//This class merges two images, by RGB values. It also accepts offsets, where as the first image is static and the offset is applied to the second image.
//The result is returned as new image. It can be truncated, to generate an image just from overlapping areas and truncate the non overlap.

class ImageMerger : public QObject
{
    Q_OBJECT

public:
    enum Channel
    {
        ALL   = 0x01,
        RED   = 0x02,
        GREEN = 0x04,
        BLUE  = 0x08
    };

    typedef unsigned int Channels;

public:
    explicit ImageMerger(const QImage& first, const QImage& second, QObject *parent = 0);
    explicit ImageMerger(QObject *parent = 0);

    ~ImageMerger();

    void setFirstImage(const QImage& img);
    void setSecondImage(const QImage& img);

    void setOffset(int off_x, int off_y);
    void enableTruncate(bool enable);

    void enableChannels(Channels toEnable);
    void disableChannels(Channels toDisable);

    QString  channelsToMergeStr();
    Channels channelsToMerge();

    bool isBusy() const;

    QImage* getMergeResult();

signals:
    void mergeFinished();

public slots:
    void startMerge();

protected:
    QImage firstImage;
    QImage secondImage;
    QImage result;

    int offsetX, offsetY;

    bool channelsEnabled[3];
    bool busy;
    bool truncate;

    QThread workerThread;
};

class MergeWorker : public QObject
{
    Q_OBJECT
public:
    MergeWorker(QImage* first, QImage* second, QObject* parent = 0);
    ~MergeWorker();

public slots:
    void doWork(ImageMerger::Channels channels, bool truncate, int off_x, int off_y);

signals:
    void mergeFinished(QImage result);

protected:
    QImage* firstImg, *secondImg;
};

#endif // IMAGEMERGER_H
