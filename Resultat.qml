import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.15

Window {
    width: 450
    height: 200
    visible: true
    title: qsTr("Résultat")
    property alias rectangle : rectangle

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 450
        height: 200
        color: "#ffffff"
        property alias text1 : text1

        Text {
            id: text1
            x: -3
            y: 47
            width: 457
            height: 107
            text: "Text"
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 16
            font.family: "Tahoma"
        }
    }
}
