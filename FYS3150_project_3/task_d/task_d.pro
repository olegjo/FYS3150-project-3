TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -fopenmp

SOURCES += main.cpp \
           ../lib.cpp

HEADERS += ../lib.h

