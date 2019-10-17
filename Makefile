CFLAGS= -g -Wall
LIBS=-lm -Iinclude

OBJDIR=bin

SRCS=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(addprefix $(OBJDIR)/, $(patsubst src/%.c,%.o,$(SRCS)))

CC=mpicc

vpath %.c src

TARGET=bin/cluster

all: $(TARGET)

$(TARGET): bin  build
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

bin:
	mkdir $(OBJDIR)

build: $(OBJECTS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LIBS)

clean:
	rm $(OBJECTS)
	rm $(TARGET)


