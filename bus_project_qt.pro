QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    logo.qrc

DISTFILES += \
    picture/20231018_190948_0000.png \
    picture/20231018_215358_0000-removebg-preview.png \
    picture/20231018_234943_0000.png \
    picture/20231019_004125_0000-removebg-preview.png \
    picture/20231101_184741_0000.png \
    picture/IMG_20231014_235549_290.jpg \
    picture/IMG_20231018_001726_237.jpg \
    picture/IMG_20231018_111648_380.jpg \
    picture/IMG_20231018_111652_285.jpg \
    picture/IMG_20231018_111722_228.jpg \
    picture/IMG_20231018_111722_228_1-removebg-preview.png \
    picture/IMG_20231018_191213_574.jpg \
    picture/IMG_20231018_191218_687.jpg \
    picture/IMG_20231018_191226_487.jpg \
    picture/Screenshot_20231021-204516_Canva.jpg \
    picture/download.png \
    picture/images (2).jpeg \
    picture/images.jpg \
    picture/images.png \
    picture/png_20231101_002715_0000.png \
    picture/profile logo 1.png \
    picture/profile logo.jpg
