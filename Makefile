CC=g++
CFLAGS=-I. -I./src
OFILES=$(patsubst src/%.cpp, src/%.o, $(wildcard src/*.cpp))

all: chess

chess: chesslib.o
	$(CC) $(CFLAGS) test.cpp chesslib.o -o $@

chesslib.o: $(OFILES)
	ld $(CFLAGS) -r $(OFILES) -o $@

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm src/*.o
	rm ./chess
	rm chesslib.o