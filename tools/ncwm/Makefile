CFLAGS += -I../../include -L../../build/ -lewmh

default:
	$(CC) $(CFLAGS) -lncurses main.c main_window.c root_detail_window.c -o ncwm

run:
	LD_LIBRARY_PATH=../../build/ ./ncwm
