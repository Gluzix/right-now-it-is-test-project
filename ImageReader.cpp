#include "ImageReader.h"
#include <QDebug>
#include <QDir>
#include <QFile>

ImageReader::ImageReader(QObject *parent)
    : QObject{parent}
{}

void ImageReader::readImages(const QString &filePaths)
{
    QStringList imagePaths;
    imagePaths = filePaths.split(",");

    for (const auto &path: imagePaths) {
        ImageItemData imageItemData;
        QString normalizedPath = QDir::fromNativeSeparators(path);
        QString imageName = normalizedPath.split("/").last();

        imageItemData.filePath = normalizedPath;
        imageItemData.fileName = imageName;
        imageItemData.data = QPixmap(normalizedPath.remove("file:///")).scaled(maximumImageSize, Qt::KeepAspectRatio);

        emit imageRead(imageItemData);
    }
}
