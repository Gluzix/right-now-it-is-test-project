#include "ImageModel.h"

ImageModel::ImageModel(QObject *parent)
    : QAbstractItemModel{parent}
{}

void ImageModel::addImageItem(std::shared_ptr<ImageItem> imageItem)
{
    if (!imageItem) {
        return;
    }

    beginInsertRows(QModelIndex(), mItems.size(), mItems.size());

    mItems.push_back(imageItem);

    endInsertRows();
}

QModelIndex ImageModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return {};
    }

    return createIndex(row, column);
}

QModelIndex ImageModel::parent(const QModelIndex &child) const
{
    // Invalid QModelIndex
    return {};
}

int ImageModel::rowCount(const QModelIndex &parent) const
{
    return mItems.size();
}

int ImageModel::columnCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant ImageModel::data(const QModelIndex &index, int role) const
{
    if (role != static_cast<int>(Roles::ImageItem)) {
        return {};
    }

    return QVariant::fromValue(mItems.at(index.row()).get());
}

QHash<int, QByteArray> ImageModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[static_cast<int>(Roles::ImageItem)] = "imageItem";
    return roles;
}

void ImageModel::onImageRead(ImageItemData imageItemData)
{
    std::shared_ptr<ImageItem> imageItem = std::make_shared<ImageItem>();

    imageItem->setData(imageItemData.data);
    imageItem->setName(imageItemData.fileName);
    imageItem->setPath(imageItemData.filePath);
    imageItem->setId(mItems.size());

    addImageItem(imageItem);
    qDebug() << mItems.size();
}
