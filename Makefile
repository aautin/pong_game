NAME = pong_game

CC = cc

FLAGS = -Wall -Werror -Wextra

LDFLAGS = -lncurses

HEADER_DIR = headers/

SRC = ./src/main.c \
	  ./src/menus.c \
	  ./src/utils.c \
	  ./src/game.c \
	  ./src/player.c \
	  ./src/ball.c \
	  ./src/score.c \
	  ./src/file_treatment.c \
	  ./src/convert_types.c \
	  ./src/random.c

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