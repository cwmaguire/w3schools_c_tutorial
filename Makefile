# Built by Grok
# (I'm learning C, I don't want to learn Make again)

CFLAGS := -Wall -Wextra -Wpedantic

sources := $(filter-out 28_a.c,$(wildcard *.c))
programs := $(patsubst %.c,%,$(sources))

all: $(programs)

28_b: 28_b.o 28_a.o
	$(CC) $(CFLAGS) $^ -o $@

28_a.o: 28_a.c 28_a.h
28_b.o: 28_b.c 28_a.h
