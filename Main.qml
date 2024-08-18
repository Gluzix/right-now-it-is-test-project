import QtQuick
import Qml.Image.Merger.Models
import Project_1

Window {
    width: 1280
    height: 760
    visible: true
    title: qsTr("Image Merger")

    DropArea {
        id: dropArea
        anchors.fill:parent
        anchors.margins: 25
        onEntered: (drag) => {
            console.log("Entered");
        }
        onDropped: (drop) => {
            console.log("Dropped");
            console.log(drop.urls);
        }
        onExited: {
            console.log("Exited");
        }

        Rectangle {
            anchors.fill:parent
            color: "gray"
        }
    }
}
