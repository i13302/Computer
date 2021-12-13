CC=g++
CFLAGS= -Wall
LIBS=-lm

PROG=Computer.out
OBJS=main.o


all: $(PROG)

$(PROG):$(OBJS)
	$(CC) -o $(PROG) $^

.SUFFIXES: .cpp .o
.cpp.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	-rm $(PROGRAM) $(OBJS)
