import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qml.Image.Merger.Models
import Qml.Image.Merger.Helpers
import Project_1
import "."

Window {
    width: 1280
    height: 760
    visible: true
    title: qsTr("Image Merger")

    Rectangle {
        id: background
        anchors.fill: parent
        color: "grey"
    }

    MainView {
        id: mainView
    }

    ImageDialog {
        id: imageDialog
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

    Rectangle {
        id: panelRectangle
        anchors.bottom: parent.bottom
        anchors.margins: 25
        x: parent.width/2 - (panelRectangle.width/2)
        width: 300
        height: 60
        radius: 30
        color: "white"
        RowLayout {
            anchors.margins: 15
            anchors.fill: parent
            Button {
                width:40
                height:40
                id: addImage
                icon.source: "attach-svgrepo-com.svg"
            }
            Button {
                width:40
                height:40
                id: removeImages
                icon.source: "trashcan-svgrepo-com.svg"
            }
            Button {
                width:40
                height:40
                id: mergeImages
                icon.source: "video-file-svgrepo-com.svg"
            }
            Button {
                width:40
                height:40
                id: zoomInMainView
                icon.source: "zoom-in-svgrepo-com.svg"
            }
            Button {
                width:40
                height:40
                id: zoomOutMainView
                icon.source: "zoom-out-svgrepo-com.svg"
            }
        }
    }
}
