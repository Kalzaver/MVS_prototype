TARGET = model
TEMPLATE = lib
CONFIG += shared c++20
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers
DEPENDPATH  += ../helpers
LIBS += -L../lib -lhelper
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
HEADERS += sqlobjects/blogobject.h
HEADERS += objects/blog.h
SOURCES += objects/blog.cpp
HEADERS += blogservice.h
SOURCES += blogservice.cpp
