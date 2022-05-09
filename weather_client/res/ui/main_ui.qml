import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Layouts 1.15

Window {
  id: wroot
  visible: true
  width: 720
  height: 480
  color: "black"
  opacity: 0.9
  title: qsTr("Weather App")

  Rectangle {
    id: layout
    anchors.centerIn: parent
    width: parent.width * 0.9
    height: parent.height * 0.9
    border.color: "#454545"
    radius: width * 0.05
    Text {
      id: name
      text: qsTr("Координаты места прогноза")
      anchors.horizontalCenter: parent.horizontalCenter
      anchors.bottom: longitudeInput.top
      anchors.bottomMargin: 40
    }

    TextInput {
      id: longitudeInput
      width: 120
      height: 20
      color: "#bf000000"
      text: qsTr("Долгота")
      font.pixelSize: 12
      anchors.horizontalCenter: parent.horizontalCenter
      y: parent.height / 2 - (latitudeInput.height + longitudeInput.height + 20 + getForecastBtn.height + 20) / 2
    }

    TextInput {
      id: latitudeInput
      width: 120
      height: 20
      color: "#bf000000"
      text: qsTr("Широта")
      font.pixelSize: 12
      anchors.horizontalCenter: parent.horizontalCenter
      anchors.top: longitudeInput.bottom
      anchors.topMargin: 20
    }

    Rectangle {
      id: getForecastBtn
      width: 120
      height: 50
      color: "#110080"
      radius: width * 0.1
      gradient: Gradient {
        GradientStop {
          position: 0
          color: "#110080"
        }

        GradientStop {
          position: 1
          color: "#260883"
        }
      }
      opacity: 0.9
      anchors.horizontalCenter: parent.horizontalCenter
      anchors.top: latitudeInput.bottom
      anchors.topMargin: 20

      Text {
        text: qsTr("Получить прогноз")
        horizontalAlignment: Text.AlignHCenter
        color: "white"
        width: parent.width
        wrapMode: Text.Wrap
        anchors.centerIn: parent
      }

      MouseArea {
        id: getForecastMouseAread
        anchors.fill: parent
        onClicked: {
          weatherUI.onGetForecastClick(longitudeInput.text, latitudeInput.text)
        }
      }
    }

    Text {
      id: errorText
      color: "#d01e1e"
      text: "sdsdsdsd"
//      visible: false


      anchors.horizontalCenter: parent.horizontalCenter
      anchors.top: getForecastBtn.bottom
      anchors.topMargin: 40

      Rectangle {
        border.color: "#d01e1e"
        width: parent.width * 1.1
        height: parent.height * 1.1
        anchors.left: parent.left
        anchors.right: parent.right
      }
    }
  }
}
