# Vars
CC = g++
CFLAGS = -Wall -Wextra -std=c++17 -I./include

# Files
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Rules
all: program

program: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) program
