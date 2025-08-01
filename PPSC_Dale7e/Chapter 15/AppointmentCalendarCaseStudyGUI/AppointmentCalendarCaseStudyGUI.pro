QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        AppointmentCalendar.cpp \
        AppointmentCalendarWindow.cpp \
        Date.cpp \
        Entry.cpp \
        EntryWithDate.cpp \
        Name.cpp \
        TimeOfDay.cpp \
        List.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AppointmentCalendar.h \
    AppointmentCalendarWindow.h \
    Date.h \
    Entry.h \
    EntryWithDate.h \
    Name.h \
    RelationType.h \
    TimeOfDay.h \
    List.h

DISTFILES += \
    CalendarFile
