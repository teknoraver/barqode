FORMS += barqodewidget.ui
HEADERS += barqode.h
SOURCES += barqode.cpp main.cpp
RESOURCES += barqode.qrc
TEMPLATE = app
CONFIG += release warn_on thread qt
TARGET = barqode
RC_FILE = barqode.rc
LIBS += -ldmtx
QT += network widgets

win32 {
	LIBS += -static
}
