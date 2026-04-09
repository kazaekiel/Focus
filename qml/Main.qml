import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import QtQuick.Window


ApplicationWindow {
    width: 320
    height: 320
    visible: true

    title: qsTr("Pomodoro Timer")

    StackView{
        id: changer
        anchors.fill: parent
        initialItem: TimerPage{}
    }
}
