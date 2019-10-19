CFLAGS= -g -Wall
LIBS=-lm -Iinclude

OBJDIR=bin

SRCS=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(addprefix $(OBJDIR)/, $(patsubst src/%.c,%.o,$(SRCS)))

CC=mpicc

vpath %.c src

TARGET=bin/cluster

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

