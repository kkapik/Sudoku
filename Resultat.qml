import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.15

Window {
    width: 700
    height: 200
    visible: true
    title: qsTr("Résultat")
    property alias rectangle : rectangle

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent
        property alias text1 : text1

        Text {
            id: text1
            text: "Text"
            anchors.fill: parent
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 16
            font.family: "Tahoma"
        }
    }
}
