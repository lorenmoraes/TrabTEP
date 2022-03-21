SRC_C = $(wildcard *.c)

SRC_H = $(wildcard *.h)

OBJ=$(SRC_C:.c=.o)

CC = gcc

CFLAGS=-c -lm  -Wall 

VALGRIND_FLAGS = VALGRIND_FLAGS=-s \
               --leak-check=full \
               --show-leak-kinds=all \
			   --show-reachable=yes \
               --track-origins=yes \
               --verbose


NAME_PROGRAM=TrabTEP

all:$(NAME_PROGRAM)

$(NAME_PROGRAM): $(OBJ)
	echo "Compilando programa"
	$(CC) -o $@ $^ -lm
  
	echo "Compilado"
  
%.o: %.c %.h 
	$(CC) -c -o $@ $< $(CFLAGS) 


main.o: main.c $(SRC_H)
	$(CC) -o $@ $< $(CFLAGS)


run: all
	@./${BIN}/${NAME_PROGRAM}
	@ echo "\n\n\n"
	@ cowsay "Deu certo"


valgrind: all
	@ clear
	@ valgrind --leak-check=full ./${NAME_PROGRAM}
	@ echo "\n\n"

clean:
	rm -rf *.o *~ $(NAME_PROGRAM)