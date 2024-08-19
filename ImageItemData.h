#pragma once

#include <QObject>
#include <QString>
#include <QPixmap>

struct ImageItemData {
    QString fileName;
    QString filePath;
    QPixmap data;
};
