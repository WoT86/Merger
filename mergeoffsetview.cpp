#include "mergeoffsetview.h"

MergeOffsetView::MergeOffsetView(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

void MergeOffsetView::wheelEvent(QWheelEvent *event)
{
    // this functions scales the view to perform zooming
    double scaleFactorIn = 1.15;
    double scaleFactorOut = 1.0 / scaleFactorIn;

    if(event->angleDelta().y() > 0)
    {
        // Zoom in
        this->scale(scaleFactorIn, scaleFactorIn);
    }
    else
    {
        // Zooming out
        this->scale(scaleFactorOut, scaleFactorOut);
    }

    // Don't call superclass handler here
    // as wheel is normally used for moving scrollbars
}
