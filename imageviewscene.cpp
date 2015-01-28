#include "imageviewscene.h"

ImageViewScene::ImageViewScene(QObject *parent) :
    QGraphicsScene(parent),
    _imgItem(0)
{
}

QGraphicsItem *ImageViewScene::loadImage(QString pathToImg)
{
    QImage img(pathToImg);

    if(!(img.isNull())) //Image exists?
    {
        if(this->_imgItem)
        {
            this->removeItem(this->_imgItem);
            delete this->_imgItem;
        }

        this->_imgItem = this->addPixmap(QPixmap::fromImage(img));
        this->setSceneRect(img.rect());

        this->currentPath = pathToImg;

        emit this->imageUpdated(this->_imgItem);

        return this->_imgItem;
    }

    return 0;
}

QString ImageViewScene::getCurrentImagePath()
{
    return this->currentPath;
}

void ImageViewScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void ImageViewScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void ImageViewScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasUrls())
    {
        this->loadImage(event->mimeData()->urls().first().toLocalFile());
    }
    event->acceptProposedAction();
}
