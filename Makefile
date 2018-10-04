CC = g++

BUILD_DIR = build
SRC_DIR = src
TARGET_DIR = bin
TARGET = $(TARGET_DIR)/game.exe

INC = -Iinclude/SDL2 -Isrc
LIB = -Llib/SDL2
W_FLAGS = -Wall -Wextra
L_FLAGS = -lmingw32 -lSDL2main -lSDL2
C_FLAGS = -std=c++11
ALL_FLAGS = $(INC) $(LIB) $(L_FLAGS) $(W_FLAGS) $(C_FLAGS)

SOURCES := $(shell wsl find $(SRC_DIR) -type f -name *.cpp)
OBJS = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.cpp=.o))

# For debugging this Makefile
print-%  : ; @echo $* = $($*)

all: $(OBJS)
	$(CC) $(OBJS) $(ALL_FLAGS) -o $(TARGET)

run: all
	$(TARGET)

clean:
	rm -rf $(BUILD_DIR)/*.o
	rm -rf $(TARGET_DIR)/*.exe

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $< $(ALL_FLAGS) -D DEBUG -c -o $@
