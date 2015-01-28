#ifndef IMAGEVIEWSCENE_H
#define IMAGEVIEWSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QImage>
#include <QGraphicsItem>
#include <QUrl>

class ImageViewScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ImageViewScene(QObject *parent = 0);

    QGraphicsItem* loadImage(QString pathToImg);

    QString getCurrentImagePath();

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

signals:
    void imageUpdated(QGraphicsItem* item);

public slots:

protected:
    QGraphicsItem* _imgItem;

    QString currentPath;
};

#endif // IMAGEVIEWSCENE_H
