TEMPLATE = app
TARGET = Reversi
QT += core \
    gui \
    qt3support
HEADERS += src/Map.h \
    src/AI.h \
    MainWindow.h \
    src/Point.h \
    src/Lines.h \
    src/ClickableLabel.h \
    reversi.h
SOURCES += src/Map.cpp \
    src/AI.cpp \
    MainWindow.cpp \
    src/Point.cpp \
    src/Lines.cpp \
    src/ClickableLabel.cpp \
    main.cpp \
    reversi.cpp
FORMS += reversi.ui
RESOURCES += 
