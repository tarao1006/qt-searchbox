QT      += core gui widgets
CONFIG  += c++14
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    searchbox.cpp

HEADERS += \
    searchbox.h

RESOURCES    += resources.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
