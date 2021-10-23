OBJS = ./src/*.cpp
CC = g++
COMPILER_FLAGS = -w -std=c++17
LINKER_FLAGS = -lglfw -lassimp
OBJ_NAME = game.exe

build: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./$(OBJ_NAME)

debug:
	leaks -atExit -- ./$(OBJ_NAME)
