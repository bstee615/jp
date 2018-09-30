OBJS = main.o log.o jp.o
INC = C:\code\libs\SDL2-2.0.8\i686-w64-mingw32\include\SDL2
LIB = C:\code\libs\SDL2-2.0.8\i686-w64-mingw32\lib
FLAGS = -Wall -Wextra
L_FLAGS = -lmingw32 -lSDL2main -lSDL2
ALL_FLAGS =  -L$(LIB) $(FLAGS) $(L_FLAGS)

EXE_NAME = jp.exe

all: $(OBJS)
	gcc $(OBJS) $(ALL_FLAGS) -o $(EXE_NAME)

run: all
	$(EXE_NAME)

clean:
	rm *.o *.exe

%.o: %.c
	gcc $< -I$(INC) $(ALL_FLAGS) -D DEBUG -c -o $@
