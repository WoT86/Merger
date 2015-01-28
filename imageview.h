#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QGraphicsView>
#include <QImage>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QGraphicsItem>

#include "imageviewscene.h"

class ImageView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ImageView(QWidget *parent = 0);

    bool loadImage(QString pathToImg);
    QString getCurrentFilePath();

protected:
    void resizeEvent(QResizeEvent* event);

signals:
    void imageUpdated(QString newFile);

public slots:

protected slots:
    void updateData(QGraphicsItem* item);

protected:
    QGraphicsItem* _imgItem;
    ImageViewScene _scene;
};

#endif // IMAGEVIEW_H
