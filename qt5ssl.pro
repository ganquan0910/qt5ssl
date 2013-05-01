#-------------------------------------------------
#
# Project created by QtCreator 2013-04-27T10:24:08
#
#-------------------------------------------------

QT       += core network testlib

QT       -= gui

MOC_DIR=tmp
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0

TARGET = ../tst_qsslserver
CONFIG   += testcase


SOURCES += \
    qsslserver.cpp \
    tst_qsslserver.cpp \
    SslSocket.cpp

HEADERS += \
    qsslserver.h \
    SslSocket.h
