QT -= core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
        main.cpp \
        dialog.cpp \
        Name.cpp

HEADERS += \
        dialog.h \
        util.h \
        Name.h \
        RelationType.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    acoustics.dat