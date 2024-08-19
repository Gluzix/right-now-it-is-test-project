#pragma once

#include "ImageItem.h"
#include "ImageItemData.h"

#include <QAbstractItemModel>

class ImageModel : public QAbstractItemModel
{
    Q_OBJECT
    enum class Roles {
        ImageItem = Qt::UserRole + 1
    };

public:
    explicit ImageModel(QObject *parent = nullptr);
    void addImageItem(std::shared_ptr<ImageItem> imageItem);

    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void onImageRead(ImageItemData imageItemData);

private:
    std::vector<std::shared_ptr<ImageItem>> mItems;
};
