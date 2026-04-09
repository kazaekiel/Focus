import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Page {
    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.fillWidth: true

            ToolButton {
                text: "<"
                onClicked: StackView.view.pop()
            }

            Label {
                text: "Configuration"
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignLeft
            }
        }
    }
}