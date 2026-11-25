CFLAGS := -Wall -Wextra -Wpedantic

programs := $(patsubst %.c,%,$(wildcard *.c))

all: $(programs)
