import QtQuick
import QtQuick.Controls

Window {
    id: imageDialog
    width:640
    height:480
    title: "Title"
    flags: Qt.Dialog

    property url imageSource

    Image {
        id: image
        width: parent.width
        height: parent.height
        fillMode: Image.PreserveAspectFit
        source: imageSource
    }
}
