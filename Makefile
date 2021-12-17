CC=g++
CFLAGS= -Wall
LIBS=-lm

PROG=Computer.out
OBJS=main.o CPU.o DEBUG.o MEMORY.o RomProg.o


all: $(PROG)

run: $(PROG)
	./$(PROG)

$(PROG):$(OBJS)
	$(CC) $(CFLAGS) $(LIBS) -o $(PROG) $^

CPU.o: CPU.hpp TYPE.hpp BUS.hpp DEBUG.hpp
MEMORY.o: MEMORY.hpp TYPE.hpp BUS.hpp DEBUG.hpp
RomProg.o: RomProg.hpp MEMORY.hpp TYPE.hpp
DEBUG.o: DEBUG.hpp

.SUFFIXES: .cpp .o
.cpp.o:
	$(CC) $(CFLAGS) $(LIBS) -c $<

.PHONY: clean
clean:
	-rm $(PROGRAM) $(OBJS)
