#pragma once

#include <ImageModel.h>

#include <QObject>
#include <QQmlApplicationEngine>

class MainManager : public QObject
{
    Q_OBJECT
public:
    explicit MainManager(QObject *parent = nullptr);
    ~MainManager() = default;
    MainManager(MainManager const& ) = delete;
    MainManager(MainManager &&) = delete;

    void registerQmlSingletons();
    const QQmlApplicationEngine &engine();
    const ImageModel &imageModel();

private:
    QQmlApplicationEngine mEngine;
    ImageModel mImageModel;
};
