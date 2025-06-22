QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
        SortedList.cpp \
        StatisticsList.cpp \
        Student.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    RelationType.h \
    SortedList.h \
    StatisticsList.h \
    Student.h

DISTFILES += \
    Statistics.dat
