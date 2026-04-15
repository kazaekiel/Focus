import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Page {
    id: configPage
    property int minFocusDuration: 1
    property int maxFocusDuration: 60
    property int minShortBreakDuration: 1
    property int maxShortBreakDuration: 60
    property int minLongBreakDuration: 1
    property int maxLongBreakDuration: 60
    property int minNbrOfCycle: 1
    property int maxNbrOfCycle: 10
    ScrollView{
        anchors.fill: parent
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
                value: timerViewModel.focusTime
                from: configPage.minFocusDuration
                to: configPage.maxFocusDuration
            }

            Param{
                id: shortBreakTime
                title: "Durée de pause courte (minutes)"
                description: "Petite pause entre les cycles de travail"
                value: timerViewModel.shortBreakTime
                from: configPage.minShortBreakDuration
                to: configPage.maxShortBreakDuration
            }

            Param{
                id: longBreakTime
                title: "Durée de pause longue (minutes)"
                description: "Grande pause après les cycles de travail"
                value: timerViewModel.longBreakTime
                from: configPage.minLongBreakDuration
                to: configPage.maxLongBreakDuration
            }

            Param{
                id: nbrOfCycles
                title: "Cycles avant pause longue"
                description: "Nombre de cycles de travail avant la pause longue"
                value: timerViewModel.nbrOfCycle
                from: configPage.minNbrOfCycle
                to: configPage.maxNbrOfCycle
            }

            RowLayout{
                Layout.alignment: Qt.AlignHCenter
                Layout.fillWidth: true
                Button{
                    id: loadButton
                    text: "Enregistrer"
                    onClicked: {
                        timerViewModel.update(focusTime.value, shortBreakTime.value,
                                                     longBreakTime.value, nbrOfCycles.value)
                        configPage.StackView.view.pop()
                    }
                }
                Button{
                    id: cancelButton
                    text: "Annuler"
                    onClicked: configPage.StackView.view.pop()
                }
            }
        }
    }


}