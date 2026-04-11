import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Page {
    id: configPage
    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.fillWidth: true

            ToolButton {
                text: "<"
                onClicked: configPage.StackView.view.pop()
            }

            Label {
                text: "Configuration"
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignLeft
            }
        }

        Param{
            id: focusTime
            title: "Durée de concentration (minutes)"
            description: "Temps de travail focalisé avant une pause"
            value: 25
            from: 10
            to: 120
        }

        Param{
            id: shortBreakTime
            title: "Durée de pause courte (minutes)"
            description: "Petite pause entre les cycles de travail"
            value: 5
            from: 5
            to: 30
        }

        Param{
            id: longBreakTime
            title: "Durée de pause longue (minutes)"
            description: "Grande pause après les cycles de travail"
            value: 15
            from: 15
            to: 30
        }

        Param{
            id: nbrOfCycles
            title: "Cycles avant pause longue"
            description: "Nombre de cycles de travail avant la pause longue"
            value: 4
            from: 1
            to: 10
        }

        RowLayout{
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            Button{
                id: loadButton
                text: "Enregistrer"
                onClicked: timerViewModel.update(focusTime.value, shortBreakTime.value,
                                                 longBreakTime.value, nbrOfCycles.value)
            }
            Button{
                id: cancelButton
                text: "Annuler"
                onClicked: configPage.StackView.view.pop()
            }
        }
    }
}