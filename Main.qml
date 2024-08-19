import QtQuick
import Qml.Image.Merger.Models
import Qml.Image.Merger.Helpers
import Project_1

Window {
    width: 1280
    height: 760
    visible: true
    title: qsTr("Image Merger")

    ListView {
        id: listView
        anchors.fill: parent
        anchors.margins: 25
        model: ImageModel
        delegate: Item {
            id: modelDelegate
            width: 200
            height: 220
            required property ImageItem imageItem

            Image {
                id: delegateImage
                width:200
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

    DropArea {
        id: dropArea
        anchors.fill:parent
        anchors.margins: 25
        onEntered: (drag) => {
            console.log("Entered");
        }
        onDropped: (drop) => {
            console.log("Dropped");
            ImageReader.readImages(drop.urls);
        }
        onExited: {
            console.log("Exited");
        }

        Rectangle {
            anchors.fill:parent
            color: "transparent"
        }
    }
}
