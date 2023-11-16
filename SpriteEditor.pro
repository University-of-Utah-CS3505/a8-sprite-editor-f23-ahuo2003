QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bucket.cpp \
    Canvas.cpp \
    Cursor.cpp \
    Eraser.cpp \
    Eyedropper.cpp \
    Filter.cpp \
    Frame.cpp \
    MainWindow.cpp \
    Pencil.cpp \
    SpriteModel.cpp \
    SpritePlayer.cpp \
    SpriteTool.cpp \
    main.cpp

HEADERS += \
    Bucket.h \
    Canvas.h \
    Cursor.h \
    Eraser.h \
    Eyedropper.h \
    Filter.h \
    Frame.h \
    MainWindow.h \
    Pencil.h \
    SpriteModel.h \
    SpritePlayer.h \
    SpriteTool.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
