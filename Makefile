CC=g++
CFLAGS= -Wall
LIBS=-lm

PROG=Computer.out
OBJS=main.o CPU.o DEBUG.o


all: $(PROG)

$(PROG):$(OBJS)
	$(CC) $(CFLAGS) $(LIBS) -o $(PROG) $^

CPU.o: CPU.hpp TYPE.hpp DEBUG.hpp
DEBUG.o: DEBUG.hpp

.SUFFIXES: .cpp .o
.cpp.o:
	$(CC) $(CFLAGS) $(LIBS) -c $<

.PHONY: clean
clean:
	-rm $(PROGRAM) $(OBJS)
