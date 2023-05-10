CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/arvore.o $(OBJ)/palavra.o 
HDRS = $(INC)/arvore.h $(INC)/palavra.h 
CFLAGS = -pg -Wall -c -I$(INC)

EXE = $(BIN)/tp1.out

$(BIN)/tp1.out: $(OBJS)
	$(CC) -pg -o $(BIN)/tp1.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/arvore.o: $(HDRS) $(SRC)/arvore.c
	$(CC) $(CFLAGS) -o $(OBJ)/arvore.o $(SRC)/arvore.c 


$(OBJ)/palavra.o: $(HDRS) $(SRC)/palavra.c
	$(CC) $(CFLAGS) -o $(OBJ)/palavra.o $(SRC)/palavra.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out
