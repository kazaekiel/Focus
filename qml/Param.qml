import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout{
    id: root

    Layout.fillWidth: true
    property int from: 5
    property int to: 60
    property int stepSize: 1

    property alias title: titleText.text
    property alias description: descriptionText.text
    property alias value: spinBox.value

    Text {
        id: titleText
        text: root.title
    }
    RowLayout{
        SpinBox{
            id: spinBox
            from: root.from
            to: root.to
            stepSize: root.stepSize

            value: root.value
            editable: true
        }
    }

    Text{
        id: descriptionText
        text: root.description
    }
}
