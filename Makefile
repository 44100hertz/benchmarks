CC?="gcc"
CFLAGS:=-Wall -O2 $(CFLAGS)
BENCH:=$(wildcard bench/*.c)
BIN:=$(patsubst bench/%.c,bin/%,$(BENCH))
LIB:=$(patsubst %.c,%.o,$(wildcard lib/*.c))

all: $(LIB) $(BIN)

clean:
	rm $(BIN) $(LIB)

lib/%.o: lib/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

bin/%: bench/%.c
	$(CC) -o $@ $< $(LIB) $(CFLAGS)

.PHONY: all clean
