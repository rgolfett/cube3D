NAME = cube3D

SRCS = 	main.c \
		get_next_line.c \
		get_next_line_utils.c \
		map_parsing.c \
		utils.c \
		ft_atoi.c \
		ft_itoa.c \
		texture_parsing.c \
		texture_files_check.c \
		texture_utils.c \
		limits.c \
		limits_utils.c \
		map_walls_parsing.c \
		parsing_utils.c \
		test.c \
		srcs/deal_key.c \
		srcs/ft_raycasting.c \
		srcs/next_frame.c \
		srcs/utils_next_frame.c \

INCLUDES = get_next_line.h \
		   cube_3D.h \

OBJS =	$(SRCS:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -g3 -Iminilibx-linux -fsanitize=address#-Werror

all : $(NAME)

$(NAME) : $(OBJS) minilibx-linux/libmlx.a
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Lminilibx-linux -lmlx -lm -lXext -lX11

minilibx-linux/libmlx.a :
		$(MAKE) -C minilibx-linux

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C minilibx-linux

fclean : clean 
		rm -f $(NAME)

re : fclean all

%.o : %.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY = all clean fclean re
