WINDOW_ID ?= 0x0
default:
	$(CC) -I../include -L../build -lewmh main.c -o test

run:
	echo "window id: $(WINDOW_ID)"
	LD_LIBRARY_PATH=../build ./test $(WINDOW_ID)

clean:
	rm test
