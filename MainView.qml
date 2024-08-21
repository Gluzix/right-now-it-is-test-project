import QtQuick
import Qml.Image.Merger.Models
import Qml.Image.Merger.Helpers

GridView {
    id: gridView
    anchors.fill: parent
    anchors.margins: 25
    model: ImageModel
    cellWidth: 220
    cellHeight: 240
    delegate: Item {
        id: modelDelegate
        width: 200
        height: 220
        required property ImageItem imageItem

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
            }
        }
    }
}
