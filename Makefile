NAME = cub3D

CC = clang

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

HEADERS = -I ./includes

LIBFT_DIR = ./libs/libft

LIBMLX_DIR = ./libs/minilibx-linux

#SRCS_DIR = ./src

ADD_LIBS = -lbsd -lXext -lX11 -L $(LIBFT_DIR) -lft -L $(LIBMLX_DIR) -lmlx

SRCS = $(wildcard ./src/*.c)

OBJS = $(SRCS:.c=.o)

RM = /bin/rm -f


all:	$(NAME)

$(NAME):	$(OBJS) libft minilibx-linux
	$(CC) $(FLAGS) $(HEADERS) $(OBJS) $(ADD_LIBS) -o $@

%.o:	%.c    #$(SRCS_DIR)/%.o:	$(SRCS_DIR)/%.c
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

libft:
	make -C $(LIBFT_DIR)

minilibx-linux:
	make -C $(LIBMLX_DIR)
	
clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)
	$(RM) ./src/*.o

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	#$(RM) *.bmp

re: fclean all

.PONY: all clean fclean re
