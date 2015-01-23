#ifndef IMAGEMERGER_H
#define IMAGEMERGER_H

#include <QObject>
#include <QImage>

//This class merges two images, by RGB values. It also accepts offsets, where as the first image is static and the offset is applied to the second image.
//The result is returned as new image. It can be truncated, to generate an image just from overlapping areas and truncate the non overlap.

class ImageMerger : public QObject
{
    Q_OBJECT
public:
    explicit ImageMerger(const QImage& first, const QImage& second, QObject *parent = 0);
    explicit ImageMerger(QObject *parent = 0);

    void setFirstImage(const QImage& first);
    void setSecondImage(const QImage& first);

    void setOffset(int off_x, int off_y);

signals:
    void mergeFinished(QImage result);

public slots:
    void startMerge();

};

#endif // IMAGEMERGER_H
