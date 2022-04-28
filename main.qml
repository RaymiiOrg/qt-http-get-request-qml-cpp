import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0

import org.raymii.NetworkExample 1.0

Window {
    id: root
    width: 400
    height: 300
    visible: true
    title: qsTr("Network Example by Raymii.org")

    property var response: undefined
    function doGetRequest(url) {
        var xmlhttp = new XMLHttpRequest()
        xmlhttp.onreadystatechange = function () {
            if (xmlhttp.readyState === XMLHttpRequest.DONE
                    && xmlhttp.status == 200) {
                response = xmlhttp.responseText
            }
        }
        xmlhttp.open("GET", url, true)
        xmlhttp.send()
    }

    Column {
        spacing: 5
        anchors.fill: parent
        anchors.margins: 5

        Row {
            spacing: 5
            Button {
                text: "Qml HTTP GET"
                onClicked: doGetRequest("http://httpbin.org/ip")
            }

            TextField {
                id: qmlResult
                text: response
            }
        }

        Row {
            spacing: 5
            Button {
                text: "C++ HTTP GET "
                onClicked: NetworkExample.doGetRequest("http://httpbin.org/ip")
            }

            TextField {
                id: cppResult
                text: NetworkExample.response
            }
        }
    }
}
