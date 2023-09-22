import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Warcraft 3 Interface Prototype"

    Column {
        spacing: 10
        width: parent.width
        height: parent.height
        Item {
            width: parent.width
            height: parent.height * 0.05

            Rectangle {
                color: "grey"
                width: parent.width
                height: parent.height

                Column {
                    spacing: 10
                    width: parent.width
                    height: parent.height

                    Item {
                        width: parent.width
                        height: parent.height

                        Button {
                            text: "Menu"
                        }
                    }

                    Item {
                        width: parent.width
                        height: parent.height

                        Button {
                            text: "Alliens"
                        }
                    }

                    Item {
                        width: parent.width
                        height: parent.height

                        Button {
                            text: "Quests"
                        }
                    }

                    Item {
                        width: parent.width
                        height: parent.height

                        Button {
                            text: "Chat"
                        }
                    }

                    Item {
                        width: parent.width
                        height: parent.height

                        Label {
                            color: "yellow"
                        }
                    }

                    Item {
                        width: parent.width
                        height: parent.height

                        Column {
                            spacing: 10
                            width: parent.width
                            height: parent.height

                            Item {
                                width: parent.width
                                height: parent.height

                                Button {
                                    text: "Menu"
                                }
                            }                        }
                    }
                }
            }
        }

        Item {
            width: parent.width
            height: parent.height * 0.7

            Rectangle {
                color: "green"
                width: parent.width
                height: parent.height
                // Добавьте объекты и кнопки в этот блок
            }
        }

        Item {
            width: parent.width
            height: parent.height

            Rectangle {
                color: "yellow"
                width: parent.width
                height: parent.height
                // Добавьте объекты и кнопки в этот блок
            }
        }
    }
}
