CC = g++

INC = C:\code\libs\SDL2-2.0.8\i686-w64-mingw32\include\SDL2
LIB = C:\code\libs\SDL2-2.0.8\i686-w64-mingw32\lib
FLAGS = -Wall -Wextra
L_FLAGS = -lmingw32 -lSDL2main -lSDL2
ALL_FLAGS =  -L$(LIB) $(FLAGS) $(L_FLAGS)

BUILD_DIR = build
SRC_DIR = src
TARGET = bin/game.exe

SOURCES := $(shell find $(SRC_DIR) -type f -name *.cpp)
OBJS = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.cpp=.o))

all: $(OBJS)
	$(CC) $(OBJS) $(ALL_FLAGS) -o $(TARGET)

run: all
	$(TARGET) -w 1024 -h 768 -f 32

clean:
	rm -r $(BUILD_DIR)/*
	rm -r $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $< -I$(INC) $(ALL_FLAGS) -D DEBUG -c -o $@
