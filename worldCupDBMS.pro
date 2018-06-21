#-------------------------------------------------
#
# Project created by QtCreator 2018-06-02T21:44:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = worldCupDBMS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    managerlogin.cpp \
    managerwindow.cpp \
    mainWindow.cpp \
    matchviewform.cpp \
    playerpage.cpp \
    teampage.cpp \
    scorepage.cpp \
    stadiumpage.cpp \
    mymodel.cpp \
    matchstaticwindow.cpp \
    fanswindow.cpp \
    staticforfans.cpp \
    searchmessage.cpp \
    themvps.cpp

HEADERS  += \
    managerlogin.h \
    sqlController.h \
    managerwindow.h \
    qss.h \
    mainwindow.h \
    matchviewform.h \
    playerpage.h \
    teampage.h \
    scorepage.h \
    stadiumpage.h \
    mymodel.h \
    matchstaticwindow.h \
    fanswindow.h \
    staticforfans.h \
    searchmessage.h \
    themvps.h

FORMS    += \
    managerlogin.ui \
    managerwindow.ui \
    mainwindow.ui \
    matchviewform.ui \
    playerpage.ui \
    teampage.ui \
    scorepage.ui \
    stadiumpage.ui \
    matchstaticwindow.ui \
    fanswindow.ui \
    staticforfans.ui \
    searchmessage.ui \
    themvps.ui

RESOURCES += \
    resourse.qrc
    RC_FILE = icon.rc

QT += sql

DISTFILES +=
