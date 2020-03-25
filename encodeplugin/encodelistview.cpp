#include "encodelistview.h"

EncodeListView::EncodeListView(QWidget *parent) : DListView(parent)
{
    setBackgroundRole(QPalette::NoRole);
    setAutoFillBackground(false);

    setVerticalScrollMode(ScrollPerPixel);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void EncodeListView::focusOutEvent(QFocusEvent *event)
{
    emit focusOut();

    DListView::focusOutEvent(event);
}

void EncodeListView::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    // Theme changed.
    QModelIndexList list = selected.indexes();
    for (const QModelIndex &index : list) {
        const QByteArray &encodeName = index.data(1919810).toByteArray();
        emit encodeChanged(encodeName);
        break;
    }

    DListView::selectionChanged(selected, deselected);
}
