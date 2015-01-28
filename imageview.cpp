#include "imageview.h"

ImageView::ImageView(QWidget *parent) :
    QGraphicsView(parent),
    _imgItem(0)
{
    this->setScene(&(this->_scene));

    connect(&(this->_scene),SIGNAL(imageUpdated(QGraphicsItem*)),this,SLOT(updateData(QGraphicsItem*)));
    this->setAcceptDrops(true);
}

bool ImageView::loadImage(QString pathToImg)
{
    this->_imgItem = this->_scene.loadImage(pathToImg);

    if(this->_imgItem)
        return true;

    return false;
}

QString ImageView::getCurrentFilePath()
{
    return this->_scene.getCurrentImagePath();
}

void ImageView::resizeEvent(QResizeEvent *event)
{
    if(this->_imgItem)
        this->fitInView(this->_imgItem,Qt::KeepAspectRatio);

    QGraphicsView::resizeEvent(event);
}

void ImageView::updateData(QGraphicsItem *item)
{
    this->_imgItem = item;
    this->fitInView(this->_imgItem,Qt::KeepAspectRatio);
    emit this->imageUpdated(this->_scene.getCurrentImagePath());
}
