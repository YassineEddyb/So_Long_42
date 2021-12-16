SRC = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c so_long_helpers.c moves.c map_validation.c render.c
LIBFT = libft/libft.a
OBJ = ${SRC:.c=.o}
NAME = so_long

all: $(NAME)

%.o: %.c
	$(CC) -Imlx -c $< -g -o $@

$(NAME): $(OBJ)
	cd libft && make && cd ..
	$(CC) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -g -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re