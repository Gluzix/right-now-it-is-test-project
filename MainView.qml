import QtQuick
import Qml.Image.Merger.Models
import Qml.Image.Merger.Helpers
import "."

GridView {
    id: gridView
    anchors.fill: parent
    anchors.margins: 25
    model: ImageModel
    cellWidth: 220
    cellHeight: 240
    delegate: MainViewItem {
        required property ImageItem imageItem
    }
}
