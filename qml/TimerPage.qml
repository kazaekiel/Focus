import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    property int routineStep: Math.floor(timerViewModel.routineCurrentIndex / 2) + 1

    ColumnLayout{
        anchors.fill: parent
        id: layout
        RowLayout{
            Layout.fillWidth: true
            id: header
            Text{
                text: "Pomodoro Timer"
            }
            Item {
                Layout.fillWidth: true
            }
            Button{
                text: "Settings"
                Layout.rightMargin: 10
                onClicked: StackView.view.push(configurationPage)
            }

            Component{
                id: configurationPage
                Configuration{}
            }

        }

        Text {
            id: status
            Layout.alignment: Qt.AlignHCenter
            text: timerViewModel.type
        }

        Text {
            id: clock
            text: timerViewModel.remainingTimeText
            fontSizeMode: Text.Fit
            font.pixelSize: 60
            minimumPixelSize: 10
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignHCenter
        }

        Text{
            text: qsTr("%1/%2").arg(routineStep)
                                .arg(timerViewModel.nbrOfCycle)
            Layout.alignment: Qt.AlignHCenter
        }

        RowLayout{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            Button{
                id: start_pause_button
                text: timerViewModel.timerStatus === "Idle" ||  timerViewModel.timerStatus === "Paused" ? "Start" : "Pause"
                onClicked: start_pause_button.text === "Start" ? timerViewModel.start() : timerViewModel.pause()
            }
            Button{
                id: reset
                text: "Reset"
                onClicked: timerViewModel.reset()
            }
            Button{
                id: skip
                text: "Skip"
                onClicked: timerViewModel.skip()
            }
        }
    }
}
