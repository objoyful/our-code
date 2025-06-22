QT -= core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG -= app_bundle

SOURCES += \
        ExamStatisticsWindow.cpp \
        SortedList.cpp \
        StatisticsList.cpp \
        Student.cpp \
        dialog.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ExamStatisticsWindow.h \
    RelationType.h \
    SortedList.h \
    StatisticsList.h \
    Student.h \
    dialog.h

DISTFILES += \
    Statistics.dat
