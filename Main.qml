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
        width: 400
        height: 40
        color: "white"
        RowLayout {
            anchors.fill: parent
            Button {
                implicitWidth:40
                implicitHeight:40
                id: addImage
                icon.source: "qrc:/attach-svgrepo-com.svg"
                icon.width: 40
                icon.height: 40
            }
            // Button {
            //     width:40
            //     height:40
            //     id: removeImages
            //     icon.source: "qrc://trashcan-svgrepo-com.svg"
            // }
            // Button {
            //     width:40
            //     height:40
            //     id: mergeImages
            //     icon.source: "qrc://video-file-svgrepo-com.svg"
            // }
            // Button {
            //     width:40
            //     height:40
            //     id: zoomInMainView
            //     icon.source: "qrc://zoom-in-svgrepo-com.svg"
            // }
            // Button {
            //     width:40
            //     height:40
            //     id: zoomOutMainView
            //     icon.source: "qrc://zoom-out-svgrepo-com.svg"
            // }
        }
    }
}
