QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-Part1-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/release/ -lJoystickLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-Part1-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/debug/ -lJoystickLibrary
else:unix: LIBS += -L$$PWD/../build-Part1-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/ -lJoystickLibrary

INCLUDEPATH += $$PWD/../build-Part1-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/include
DEPENDPATH += $$PWD/../build-Part1-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/include
