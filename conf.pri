CONFIG -= debug_and_release debug_and_release_target

MOC_DIR = $$PWD/.moc
OBJECTS_DIR = $$PWD/.obj
UI_DIR = $$PWD/.ui
RCC_DIR = $$PWD/.rcc

INCLUDEPATH += $$UI_DIR $$MOC_DIR


isEmpty(PREFIX) {
    PREFIX = /usr/local
}

BINDIR = $$PREFIX/bin
DATADIR = $$PREFIX/share/qomp

DEFINES += QOMP_DATADIR='\\"$$DATADIR\\"'

unix:!android {
    !mac:DEFINES += HAVE_X11
    contains(QMAKE_HOST.arch, x86_64):LIB_SUFFIX = 64
    LIBSDIR = $$PREFIX/lib$$LIB_SUFFIX
    PLUGSDIR = $$LIBSDIR/qomp/plugins
    DEFINES += QOMP_PLUGSDIR='\\"$$PLUGSDIR\\"'
}

#mac {
#    QMAKE_MAC_SDK = macosx10.8
#    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.8
#}

CONFIG(debug, debug|release) {
    DEFINES += DEBUG_OUTPUT
}

greaterThan(QT_MAJOR_VERSION, 4) {
    !android:  QT += widgets

    DEFINES += HAVE_QT5
    CONFIG += c++11
}
else {
    QMAKE_CXXFLAGS += -std=c++11

    defineReplace(shell_path) {
        var = $$1
        win32: var ~= s,/,\\,g
        return ($$quote($$var))
    }

    defineReplace(system_path) {
        return ($$shell_path($$1))
    }
}

android {
    QT += quick qml androidextras
    DEFINES += QOMP_MOBILE
}

CONFIG += warn_on
