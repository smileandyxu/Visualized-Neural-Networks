QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

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
    app/app.cpp \
    common/Common.cpp \
    common/Graph.cpp \
    common/neurons.cpp \
    main.cpp \
    model/NetModel.cpp \
    model/math_utils.cpp \
    view/AboutView.cpp \
    view/ConfigView.cpp \
    view/NetView.cpp \
    view/NeuronView.cpp \
    view/TutorialView.cpp \
    view/WeightView.cpp \
    view/utils.cpp \
    viewmodel/NetViewModel.cpp

HEADERS += \
    model/math_utils.h \
    app/app.h \
    common/Common.h \
    common/Graph.h \
    common/neurons.h \
    common/weights.h \
    model/NetModel.h \
    view/AboutView.h \
    view/ConfigView.h \
    view/NetView.h \
    view/NeuronView.h \
    view/TutorialView.h \
    view/WeightView.h \
    view/utils.h \
    viewmodel/NetViewModel.h

FORMS += \
    view/About.ui \
    view/ConfigView.ui \
    view/NetView.ui \
    view/NeuronView.ui \
    view/Tutorial.ui \
    view/WeightView.ui

TRANSLATIONS += \
    Visualized_Neural_Networks_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Visualized_Neural_Networks.qrc
