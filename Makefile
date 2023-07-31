NAME = pong_game

CC = cc

FLAGS = -Wall -Werror -Wextra

LDFLAGS = -lncurses

HEADER_DIR = headers/

SRC = ./src/main.c \
	  ./src/menus.c \
	  ./src/utils.c \
	  ./src/game.c \
	  ./src/score.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) $(LDFLAGS)

%.o: %.c 
	$(CC) -c -o $@ $^ $(FLAGS) -I $(HEADER_DIR)

.PHONY: all

all : $(TARGET)

clean:
	rm -f ./src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean
	make