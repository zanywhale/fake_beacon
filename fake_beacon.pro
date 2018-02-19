TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -ltins
LIBS += -pthread
LIBS += -lpcap

SOURCES += main.cpp \
    attackBeacon.cpp \
    networkInfo.cpp

HEADERS += \
    attackBeacon.h \
    networkInfo.h
