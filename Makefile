OBJ = src/xcb.c \
	src/collections.c \
	src/icccm.c \
	src/ewmh.c

CFLAGS += -I./include -lxcb -fPIC -Wall -O2

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

install:
	rm -rf /usr/include/libewmh
	cp -r include/libewmh /usr/include/
	cp build/libewmh.so.$(VERSION) /usr/lib/
	cp -P build/libewmh.so.$(VERSION_MAJOR).$(VERSION_MINOR) /usr/lib/
	cp -P build/libewmh.so.$(VERSION_MAJOR) /usr/lib/
	cp -P build/libewmh.so /usr/lib/

clean:
	rm -rf build
	rm -rf src/*.o
