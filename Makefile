SRC = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c so_long_helpers.c moves.c map_validation.c render.c exit.c
LIBFT = libft/libft.a
OBJ = ${SRC:.c=.o}
GFLAGS = -Wall -Wextra -Werror
NAME = so_long

all: $(NAME)

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	cd libft && make && cd ..
	$(CC) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	cd libft && make clean && cd ..
	rm -rf $(OBJ)

fclean : clean
	cd libft && make fclean && cd ..
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re