import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.15

Window {
    id : root
    color: "#e6ecfa"
    width: 650+5
    height: 712+5
    visible: true
    title: qsTr("Sudoku")

    function check(){
        vueObjetCpt.verif_matrice();
        var verif = vueObjetCpt.verifier;
        if(verif===1){
            result.visible=true;
            result.rectangle.color="#8ee637";
            result.rectangle.text1.text="Bravo vous avez réussi la partie !";
        }
        else{  result.visible=true;
            result.rectangle.color="#666666";
            result.rectangle.text1.text="Il y a une erreur, réessayez !";
        }
    }

    function set_chiffre_actif(i){
        vueObjetCpt.set_chiffre_actif(i);
        var chiffre_IsActif = vueObjetCpt.coloration
        var values = vueObjetCpt.values;
        var l
        var c
        for(l=0;l<9;l++){
            for(c=0;c<9;c++){
                var v = repeater.itemAt(l).rep.itemAt(c).input
                v.text=values[l][c];
            }
        }
    }

    Component.onCompleted:{
        var values=vueObjetCpt.values;
        var i;
        for(i=0;i<9;i++){
            var t = repeater.itemAt(0).rep.itemAt(i).input
            t.text=values[0][i]
            if(values[0][i]!==''){
                t.readOnly=true
                t.color="#000000"
                t.font.bold = true
            }
        }
        for(i=0;i<9;i++){
            var k = repeater.itemAt(1).rep.itemAt(i).input
            k.text=values[1][i]
            if(values[1][i]!==''){
                k.readOnly=true
                k.color="#000000"
                k.font.bold = true
            }
        }
        for(i=0;i<9;i++){
            var l = repeater.itemAt(2).rep.itemAt(i).input
            l.text=values[2][i]
            if(values[2][i]!==''){
                l.readOnly=true
                l.color="#000000"
                l.font.bold = true
            }
        }
        for(i=0;i<9;i++){
            var m = repeater.itemAt(3).rep.itemAt(i).input
            m.text=values[3][i]
            if(values[3][i]!==''){
                m.readOnly=true
                m.color="#000000"
                m.font.bold = true
            }
        }
        for(i=0;i<9;i++){
            var n = repeater.itemAt(4).rep.itemAt(i).input
            n.text=values[4][i]
            if(values[4][i]!==''){
                n.readOnly=true
                n.color="#000000"
                n.font.bold = true
            }
        }
        for(i=0;i<9;i++){
            var p = repeater.itemAt(5).rep.itemAt(i).input
            p.text=values[5][i]
            if(values[5][i]!==''){
                p.readOnly=true
                p.color="#000000"
                p.font.bold = true
            }
        }
        for(i=0;i<9;i++){
            var q = repeater.itemAt(6).rep.itemAt(i).input
            q.text=values[6][i]
            if(values[6][i]!==''){
                q.readOnly=true
                q.color="#000000"
                q.font.bold = true
            }
        }
        for(i=0;i<9;i++){
            var s = repeater.itemAt(7).rep.itemAt(i).input
            s.text=values[7][i]
            if(values[7][i]!==''){
                s.readOnly=true
                s.color="#000000"
                s.font.bold = true
            }
        }
        for(i=0;i<9;i++){
            var j = repeater.itemAt(8).rep.itemAt(i).input
            j.text=values[8][i]
            if(values[8][i]!==''){
                j.readOnly=true
                j.color="#000000"
                j.font.bold = true
            }
        }
    }
    property alias repeater : repeater

    Rectangle{
        id : background
        x:3
        y:3
        color : "black"
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -30
        anchors.horizontalCenter: parent.horizontalCenter
        width : childrenRect.width+6
        height : childrenRect.height+6


    Grid{
        id : grid
        x: 3
        y:3
        rows:3
        columns:3
        spacing :2
        Repeater{
            id : repeater
            model : 9

            Carre{
                id : case1
                width : 213
                height:213
            }
        }
    }
}

    Button {
        id: button_check
        x: 8
        y: 660
        width: 132
        height: 40
        text: qsTr("Vérifier la grille")
        anchors.bottom: parent.bottom
        highlighted: false
        anchors.horizontalCenterOffset: -250
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onClicked:{ check();
            button_check.highlighted = true
        }
    }

    Resultat{
        id :result
        visible: false
    }

    Button {
        id: button1
        x: 200
        y: 660
        width: 40
        height: 40
        text: qsTr("1")
        anchors.bottom: parent.bottom
        anchors.horizontalCenterOffset: -120
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onPressed: {highlighted = true}
        onReleased: {highlighted= false}
        onClicked:set_chiffre_actif(1)
    }

    Button {
        id: button2
        x: 250
        y: 660
        width: 40
        height: 40
        text: qsTr("2")
        anchors.bottom: parent.bottom
        anchors.horizontalCenterOffset: -70
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onPressed: {highlighted = true}
        onReleased: {highlighted= false}
        onClicked: set_chiffre_actif(2)
    }

    Button {
        id: button3
        x: 300
        y: 660
        width: 40
        height: 40
        text: qsTr("3")
        anchors.bottom: parent.bottom
        anchors.horizontalCenterOffset: -20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onPressed: {highlighted = true}
        onReleased: {highlighted= false}
        onClicked: set_chiffre_actif(3)
    }

    Button {
        id: button4
        x: 350
        y: 660
        width: 40
        height: 40
        text: qsTr("4")
        anchors.bottom: parent.bottom
        anchors.horizontalCenterOffset: 30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onPressed: {highlighted = true}
        onReleased: {highlighted= false}
        onClicked: set_chiffre_actif(4)
    }

    Button {
        id: button5
        x: 400
        y: 660
        width: 40
        height: 40
        text: qsTr("5")
        anchors.bottom: parent.bottom
        anchors.horizontalCenterOffset: 80
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onPressed: {highlighted = true}
        onReleased: {highlighted= false}
        onClicked: set_chiffre_actif(5)
    }

    Button {
        id: button6
        x: 450
        y: 660
        width: 40
        height: 40
        text: qsTr("6")
        anchors.bottom: parent.bottom
        anchors.horizontalCenterOffset: 130
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onPressed: {highlighted = true}
        onReleased: {highlighted= false}
        onClicked: set_chiffre_actif(6)
    }

    Button {
        id: button7
        x: 500
        y: 660
        width: 40
        height: 40
        text: qsTr("7")
        anchors.bottom: parent.bottom
        anchors.horizontalCenterOffset: 180
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onPressed: {highlighted = true}
        onReleased: {highlighted= false}
        onClicked: set_chiffre_actif(7)
    }

    Button {
        id: button8
        x: 550
        y: 660
        width: 40
        height: 40
        text: qsTr("8")
        anchors.bottom: parent.bottom
        anchors.horizontalCenterOffset: 230
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onPressed: {highlighted = true}
        onReleased: {highlighted= false}
        onClicked: set_chiffre_actif(8)
    }

    Button {
        id: button9
        x: 600
        y: 660
        width: 40
        height: 40
        text: qsTr("9")
        anchors.bottom: parent.bottom
        anchors.horizontalCenterOffset: 280
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onPressed: {highlighted = true}
        onReleased: {highlighted= false}
        onClicked: set_chiffre_actif(9)
    }

}

