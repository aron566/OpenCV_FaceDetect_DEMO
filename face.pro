QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
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

#windows动态库
win32: INCLUDEPATH += C:\OPENCV_INSTALL\include\opencv2 \
               C:\OPENCV_INSTALL\include
win32: LIBS += -LC:/OPENCV_INSTALL/x64/mingw/lib/ -llibopencv_aruco440.dll \
libopencv_calib3d440.dll \
libopencv_core440.dll \
libopencv_dnn440.dll \
libopencv_features2d440.dll \
libopencv_flann440.dll \
libopencv_gapi440.dll \
libopencv_highgui440.dll \
libopencv_imgcodecs440.dll \
libopencv_imgproc440.dll \
libopencv_ml440.dll \
libopencv_objdetect440.dll \
libopencv_photo440.dll \
libopencv_stitching440.dll \
libopencv_video440.dll \
libopencv_videoio440.dll
