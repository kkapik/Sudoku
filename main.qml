import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.15

Window {
    id : root
    color: 'black'
    width: 650
    height: 712
    visible: true
    title: qsTr("Sudoku")

    function check(){
        vueObjetCpt.verif_matrice();
        var verif = vueObjetCpt.verifier;
        if(verif===1){
            result.visible=true;
            result.rectangle.color="moccasin";
            result.rectangle.text1.text="Bravo vous avez réussi la partie !";
        }
        else{  result.visible=true;
            result.rectangle.color="lightgray";
            result.rectangle.text1.text="Vous avez échoué, essayez une autre fois !";
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
                t.color="darkblue"
            }
        }
        for(i=0;i<9;i++){
            var k = repeater.itemAt(1).rep.itemAt(i).input
            k.text=values[1][i]
            if(values[1][i]!==''){
                k.readOnly=true
                k.color="darkblue"
            }
        }
        for(i=0;i<9;i++){
            var l = repeater.itemAt(2).rep.itemAt(i).input
            l.text=values[2][i]
            if(values[2][i]!==''){
                l.readOnly=true
                l.color="darkblue"
            }
        }
        for(i=0;i<9;i++){
            var m = repeater.itemAt(3).rep.itemAt(i).input
            m.text=values[3][i]
            if(values[3][i]!==''){
                m.readOnly=true
                m.color="darkblue"
            }
        }
        for(i=0;i<9;i++){
            var n = repeater.itemAt(4).rep.itemAt(i).input
            n.text=values[4][i]
            if(values[4][i]!==''){
                n.readOnly=true
                n.color="darkblue"
            }
        }
        for(i=0;i<9;i++){
            var p = repeater.itemAt(5).rep.itemAt(i).input
            p.text=values[5][i]
            if(values[5][i]!==''){
                p.readOnly=true
                p.color="darkblue"
            }
        }
        for(i=0;i<9;i++){
            var q = repeater.itemAt(6).rep.itemAt(i).input
            q.text=values[6][i]
            if(values[6][i]!==''){
                q.readOnly=true
                q.color="darkblue"
            }
        }
        for(i=0;i<9;i++){
            var s = repeater.itemAt(7).rep.itemAt(i).input
            s.text=values[7][i]
            if(values[7][i]!==''){
                s.readOnly=true
                s.color="darkblue"
            }
        }
        for(i=0;i<9;i++){
            var j = repeater.itemAt(8).rep.itemAt(i).input
            j.text=values[8][i]
            if(values[8][i]!==''){
                j.readOnly=true
                j.color="darkblue"
            }
        }
    }
    property alias repeater : repeater
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

    Button {
        id: button
        x: 8
        y: 652
        width: 132
        height: 55
        text: qsTr("Check")
        font.weight: Font.ExtraLight
        font.pointSize: 12
        onClicked: check()
    }
    Resultat{
        id :result
        visible: false}
}

