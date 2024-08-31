NAME= fractol
FILES= main.c init.c fractol.c events.c math.c
OBJS= $(FILES:.c=.o)
INCLUDE= fractol.h
CC= cc
FLAGS= -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

MINILIBX = ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -g

GIT_CLONE = git clone
MINILIBX_URL = https://github.com/42Paris/minilibx-linux.git

all: minilibx-linux $(NAME)

minilibx-linux:
	$(GIT_CLONE) $(MINILIBX_URL)
	make -C $@
	
$(NAME): $(LIBFT) $(OBJS) $(INCLUDE) minilibx-linux/libmlx_Linux.a
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX)


%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -rf minilibx-linux
	make -C libft fclean

re: fclean all

.PHONY : all clean fclean re 
