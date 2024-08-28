import QtQuick
import "."

Item {
    id: modelDelegate
    width: 200
    height: 220

    Image {
        id: delegateImage
        width: 200
        height: 200
        fillMode: Image.PreserveAspectFit
        source: imageItem.path
    }

    Text {
        id: delegateText
        y: delegateImage.height + 5
        text: imageItem.name
    }

    MouseArea {
        id: delegateMouseArea
        anchors.fill: parent
        onClicked:  {
            console.log(imageItem.path);
            imageDialog.imageSource = imageItem.path;
            imageDialog.show();
        }
    }
}

