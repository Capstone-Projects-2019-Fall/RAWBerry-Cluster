CFLAGS= -g 
LIBS=-lm -Iinclude

OBJDIR=bin

SRCS=$(wildcard src/**/*.c src/*.c)
OBJS = $(patsubst test/%.c,%.o,$(SRCS))
OBJECTS=$(addprefix $(OBJDIR)/, $(patsubst src/%.c,%.o,$(OBJS)))

CC=mpicc
vpath 
vpath %.c src
vpath %.c test

TARGET=bin/cluster

test: CFLAGS += -DTEST
test: SRCS += test/stubs.c
test: bin/stubs.o $(TARGET)


all: $(TARGET)

$(TARGET):  build
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)


build: $(OBJECTS)

$(OBJDIR)/%.o: %.c bin
	$(CC) $(CFLAGS) -c -o $@ $< $(LIBS)


bin:
	mkdir $(OBJDIR)
clean:
	rm bin/*

