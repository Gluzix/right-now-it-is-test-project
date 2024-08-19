#pragma once

#include <QPixmap>
#include <QObject>
#include <qqml.h>

class ImageItem : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit ImageItem(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &newName);
    void resetName();

    QString path() const;
    void setPath(const QString &newPath);
    void resetPath();

    QPixmap data() const;
    void setData(const QPixmap &newData);
    void resetData();

    int id() const;
    void setId(int newId);
    void resetId();

signals:
    void dataChanged();
    void alternativeTextChanged();
    void nameChanged();
    void pathChanged();

    void idChanged();

private:
    // QByteArray mData;
    QPixmap mData;
    QString mName;
    QString mPath;
    int mId;

    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString path READ path WRITE setPath RESET resetPath NOTIFY pathChanged FINAL)
    Q_PROPERTY(QPixmap data READ data WRITE setData RESET resetData NOTIFY dataChanged FINAL)
    Q_PROPERTY(int id READ id WRITE setId RESET resetId NOTIFY idChanged FINAL)
};

