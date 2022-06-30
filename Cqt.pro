QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CCreature.cpp \
    hint.cpp \
    introduction.cpp \
    introduction2.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow1_2.cpp \
    mainwindow2.cpp \
    mainwindow_help.cpp \
    registerpage.cpp \
    save_request.cpp \
    tmpwindow.cpp

HEADERS += \
    CCreature.h \
    hint.h \
    introduction.h \
    introduction2.h \
    login.h \
    mainwindow.h \
    mainwindow1_2.h \
    mainwindow2.h \
    mainwindow_help.h \
    registerpage.h \
    save_request.h \
    tmpwindow.h \
    ui_introduction.h \
    ui_introduction2.h \
    ui_login.h \
    ui_mainwindow.h \
    ui_mainwindow2.h \
    ui_mainwindow_help.h \
    ui_registerpage.h \
    ui_registerpage.h \
    ui_tmpwindow.h

FORMS += \
    hint.ui \
    introduction.ui \
    introduction2.ui \
    login.ui \
    mainwindow.ui \
    mainwindow1_2.ui \
    mainwindow2.ui \
    mainwindow_help.ui \
    registerpage.ui \
    save_request.ui \
    tmpwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
