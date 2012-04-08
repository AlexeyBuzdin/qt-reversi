TEMPLATE = app
TARGET = Reversi
QT += core \
    gui \
    qt3support
HEADERS += src/ClickableLabel.h \
    reversi.h
SOURCES += src/ClickableLabel.cpp \
    main.cpp \
    reversi.cpp
FORMS += reversi.ui
RESOURCES += 
