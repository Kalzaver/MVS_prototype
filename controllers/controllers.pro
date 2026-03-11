TARGET = controller
TEMPLATE = lib
CONFIG += shared c++20
QT += network sql xml qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers ../models
DEPENDPATH  += ../helpers ../models
LIBS += -L../lib -lhelper -lmodel
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)

HEADERS += applicationcontroller.h
SOURCES += applicationcontroller.cpp
HEADERS += blogcontroller.h
SOURCES += blogcontroller.cpp
HEADERS += cdatamanagercontroller.h
SOURCES += cdatamanagercontroller.cpp
HEADERS += webcontroller.h
SOURCES += webcontroller.cpp
