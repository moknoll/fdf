CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft 
LDFLAGS = -L../libft -lft -L../mlx -lmlx_Linux -lX11 -lXext -lm
SRC = utils.c parsing.c testfdf.c
OBJ = $(SRC:.c=.o)
NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS )$(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
