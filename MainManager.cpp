#include "MainManager.h"
#include <QGuiApplication>
#include <ImageItem.h>

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
}

void MainManager::registerQmlSingletons()
{
    qmlRegisterSingletonInstance("Qml.Image.Merger.Models", 1, 0, "ImageModel", &mImageModel);
}

const QQmlApplicationEngine &MainManager::engine()
{
    return mEngine;
}

const ImageModel &MainManager::imageModel()
{
    return mImageModel;
}
