import QtQuick
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
    }
}
