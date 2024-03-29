QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Compression_Decompression.cpp \
    Graph.cpp \
    Search.cpp \
    buildGraph.cpp \
    build_queue.cpp \
    convert_jason.cpp \
    error_detection_correction.cpp \
    main.cpp \
    mainwindow.cpp \
    minifying.cpp \
    node.cpp \
    prettifying.cpp \
    supporting_function.cpp \
    tree.cpp

HEADERS += \
    Graph.h \
    header.h \
    mainwindow.h \
    node.h \
    tree.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc
RC_ICONS = image.ico

DISTFILES += \
    image.ico
