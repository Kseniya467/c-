CXX = g++
CXXFLAGS = -Wall -g -std=c++11  

EXEC = holod

all: $(EXEC)

$(EXEC): main.o Holod.o
 $(CXX) $(CXXFLAGS) -o $(EXEC) main.o Holod.o

main.o: main.cpp Holod.h
 $(CXX) $(CXXFLAGS) -c main.cpp

Holod.o: Holod.cpp Holod.h
 $(CXX) $(CXXFLAGS) -c Holod.cpp

clean:
 rm -f *.o $(EXEC)
