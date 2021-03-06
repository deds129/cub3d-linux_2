# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanisha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 12:27:45 by hanisha           #+#    #+#              #
#    Updated: 2021/01/09 12:27:49 by hanisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FOR MACOS
NAME = cub3D
SRCS 	=		main.c \
				./gnl/get_next_line.c \
				./gnl/get_next_line_utils.c \
				ft_errors.c \
				ft_minilib.c \
                ft_resolution.c \
                ft_texture.c \
                ft_parse_utils.c \
				ft_read_cub.c \
				ft_color.c \
				ft_free_all.c \
				ft_map_parse.c \
				ft_utils.c \
				ft_launch_game.c \
				test.c

OBJ = $(SRCS:.c=.o)
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Wextra -Imlx_lnx
DEBUGFLAGS = -g -fsanitize=address
RM 		= 	rm -rf
#can change to static libx ./minilibx_mac/mlx.h
HEADERS = ./includes/cub.h ./includes/get_next_line.h \
			./includes/libft.h ./minilibx_mac/mlx.h

OFLAGS = -L$(LIBFT) -lft -lm -framework OpenGL -framework AppKit -lmlx -Lminilibx_mac

.PHONY: all clean fclean re

all: comp_lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(DEBUGFLAGS) $(CFLAGS) $(OBJ) $(OFLAGS) -o $(NAME)

comp_lib:
	$(MAKE) bonus -C ./libft/
	$(MAKE) -C ./libft/

%.o: %.c $(HEADERS)
	@$(CC) $(DEBUGFLAGS) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	${RM} ${OBJ}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}
	@echo "@ added"

re: fclean all