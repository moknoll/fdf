CC = gcc

CFLAGS = -Wall -Wextra

SRC = 

OBJ = $(SRC:.c=.o)

NAME = libft.a

AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all