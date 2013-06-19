#------------------------------
#
# Project created by QtCreator
#
#------------------------------

QT       += core

QT       -= gui

TARGET = helloWorld
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

#where the OpenCV header files are
#(if you followed the tutorial, the include folder
#should be in ../build_with_Qt/release/include and
#../build_with_Qt/debug/include)
INCLUDEPATH += D:/Applications/opencv/build_with_Qt/include \

#two configuration: release and debug
CONFIG(release,debug|release){
    LIBS += -LD:/Applications/opencv/build_with_Qt/release/lib \
    #if library name is lib[name].lib, you should write -l[name]
    -lopencv_core243 \
    -lopencv_highgui243 \
    -lopencv_imgproc243 \
    -lopencv_features2d243 \
    -lopencv_calib3d243 \
    -lopencv_contrib243 \
    -lopencv_flann243 \
    -lopencv_gpu243 \
    -lopencv_legacy243 \
    -lopencv_ml243 \
    -lopencv_objdetect243 \
    -lopencv_ts243 \
    -lopencv_video243
}

CONFIG(debug,debug|release){
    LIBS += -LD:/Applications/opencv/build_with_Qt/debug/lib \
    #if library name is lib[name].lib, you should write -l[name]
    -lopencv_core243d \
    -lopencv_highgui243d \
    -lopencv_imgproc243d \
    -lopencv_features2d243d \
    -lopencv_calib3d243d \
    -lopencv_contrib243d \
    -lopencv_flann243d \
    -lopencv_gpu243d \
    -lopencv_legacy243d \
    -lopencv_ml243d \
    -lopencv_objdetect243d \
    -lopencv_ts243d \
    -lopencv_video243d
}
