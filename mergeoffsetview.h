#ifndef MERGEOFFSETVIEW_H
#define MERGEOFFSETVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>

class MergeOffsetView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MergeOffsetView(QWidget *parent = 0);

signals:

public slots:

protected:
    void wheelEvent(QWheelEvent *event);

};

#endif // MERGEOFFSETVIEW_H
