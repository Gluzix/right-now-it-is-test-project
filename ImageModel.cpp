#include "ImageModel.h"

ImageModel::ImageModel(QObject *parent)
    : QAbstractItemModel{parent}
{}

void ImageModel::addImageItem(std::shared_ptr<ImageItem> imageItem)
{
    if (!imageItem) {
        return;
    }

    mItems.push_back(imageItem);
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
