#include "MainManager.h"

#include "ImageItemData.h"
#include "ImageItem.h"

#include <QGuiApplication>

MainManager::MainManager(QObject *parent)
    : QObject{parent}
{
    registerQmlSingletons();

    QObject::connect(
        &mEngine,
        &QQmlApplicationEngine::objectCreationFailed,
        qGuiApp,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    const QUrl url(u"qrc:/Project_1/Main.qml"_qs);
    mEngine.load(url);

    connect(&mImageReader, &ImageReader::imageRead, &mImageModel, &ImageModel::onImageRead);
}

void MainManager::registerQmlSingletons()
{
    qmlRegisterSingletonInstance("Qml.Image.Merger.Models", 1, 0, "ImageModel", &mImageModel);
    qmlRegisterSingletonInstance("Qml.Image.Merger.Helpers", 1, 0, "ImageReader", &mImageReader);
}

const QQmlApplicationEngine &MainManager::engine()
{
    return mEngine;
}

const ImageModel &MainManager::imageModel()
{
    return mImageModel;
}
