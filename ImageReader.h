#pragma once

#include "ImageItemData.h"

#include <QSize>
#include <QObject>
#include <QPixmap>

class ImageReader : public QObject
{
    Q_OBJECT
public:
    explicit ImageReader(QObject *parent = nullptr);

public slots:
    Q_INVOKABLE void readImages(const QString &filePaths);

signals:
    void imageRead(const ImageItemData &imageItemData);

private:
    const QSize maximumImageSize{200, 200};
};
