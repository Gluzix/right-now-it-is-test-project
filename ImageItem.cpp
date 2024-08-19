#include "ImageItem.h"

ImageItem::ImageItem(QObject *parent)
    : QObject{parent}
{}

QString ImageItem::name() const
{
    return mName;
}

void ImageItem::setName(const QString &newName)
{
    if (mName == newName)
        return;
    mName = newName;
    emit nameChanged();
}

void ImageItem::resetName()
{
    setName({}); // TODO: Adapt to use your actual default value
}

QString ImageItem::path() const
{
    return mPath;
}

void ImageItem::setPath(const QString &newPath)
{
    if (mPath == newPath)
        return;
    mPath = newPath;
    emit pathChanged();
}

void ImageItem::resetPath()
{
    setPath({}); // TODO: Adapt to use your actual default value
}

QPixmap ImageItem::data() const
{
    return mData;
}

void ImageItem::setData(const QPixmap &newData)
{
    mData = newData;
    emit dataChanged();
}

void ImageItem::resetData()
{
    setData({}); // TODO: Adapt to use your actual default value
}

int ImageItem::id() const
{
    return mId;
}

void ImageItem::setId(int newId)
{
    if (mId == newId)
        return;
    mId = newId;
    emit idChanged();
}

void ImageItem::resetId()
{
    setId({}); // TODO: Adapt to use your actual default value
}

