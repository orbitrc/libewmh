SOURCES += src/xcb.c \
    src/collections.c \
    src/icccm.c \
    src/ewmh.c \
    tools/ncwm/main.c \
    tools/ncwm/main_window.c \
    tools/ncwm/root_detail_window.c

HEADERS += include/libewmh/base.h \
    include/libewmh/xcb/xcb.h \
    include/libewmh/icccm.h \
    include/libewmh/ewmh.h \
    tools/ncwm/window.h \
    tools/ncwm/main_window.h \
    tools/ncwm/root_detail_window.h

INCLUDEPATH += ./include
