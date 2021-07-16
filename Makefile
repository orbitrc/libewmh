OBJ = src/xcb.c \
	src/icccm.c

CFLAGS += -I./include -lxcb -Wall -O2

VERSION_MAJOR = 0
VERSION_MINOR = 1
VERSION_PATCH = 0
VERSION = $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)
SONAME = libewmh.so.$(VERSION_MAJOR)

default: $(OBJ)
	mkdir -p build
	$(CC) -shared $(CFLAGS) -Wl,-soname,$(SONAME) -o build/libewmh.so.$(VERSION) $^
	ln -f -s libewmh.so.$(VERSION) build/libewmh.so.$(VERSION_MAJOR).$(VERSION_MINOR)
	ln -f -s libewmh.so.$(VERSION_MAJOR).$(VERSION_MINOR) build/libewmh.so.$(VERSION_MAJOR)
	ln -f -s libewmh.so.$(VERSION_MAJOR) build/libewmh.so

src/%.o: src/%.c
	$(CC) -c $(CFLAGS) -fPIC -o $@ $<

clean:
	rm -rf build
	rm -rf src/*.o
