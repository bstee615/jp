CC = g++

INC = -Iinclude/SDL2 -Isrc/
LIB = -Llib/SDL2
W_FLAGS = -Wall -Wextra
L_FLAGS = -lmingw32 -lSDL2main -lSDL2
ALL_FLAGS =  $(LIB) $(W_FLAGS) $(L_FLAGS)

BUILD_DIR = build
SRC_DIR = src
TARGET = bin/game.exe

SOURCES := $(shell find $(SRC_DIR) -type f -name *.cpp)
OBJS = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.cpp=.o))

all: $(OBJS)
	$(CC) $(OBJS) $(ALL_FLAGS) -o $(TARGET)

run: all
	$(TARGET)

clean:
	rm -rf $(BUILD_DIR)/*.o
	rm -rf $(BUILD_DIR)/*.exe

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $< $(INC) $(ALL_FLAGS) -D DEBUG -c -o $@
