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

#FOR LINUX
CFLAGS 	=  	-Wall -Wextra -Werror
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
				ft_free_all.c

OBJS 	= 	$(SRCS:.c=.o)
CC 		= 	gcc
NAME 	= 	cub3D
RM 		= 	rm -rf

P_LIBFT	= 	./libft/


#Linux
MLX_PATH = ./minilibx-linux
MLX = libmlx.a
LMFLAGS = -Imlx_linux -Lmlx_linux
LIBS = -lmlx -lXext -lX11 -lm


.c.o:
	${CC} ${GFLAG} ${LMFLAGS} -c $< -o ${<:.c=.o}

all:  ${NAME}

${NAME}: comp_lib ${MLX} ${OBJS}
	${CC} ${CFLAGS} ${LMFLAGS} ${OBJS} ${P_LIBFT}libft.a ${LIBS} -o ${NAME}

$(MLX):
				@$(MAKE) -C ${MLX_PATH}
#				@mv ${MLX_PATH}/$(MLX) .

comp_lib:
	$(MAKE) bonus -C ${P_LIBFT}
	$(MAKE) -C ./libft/


clean:
	$(MAKE) clean -C ${P_LIBFT}
	$(MAKE) clean -C ${MLX_PATH}
	${RM} ${OBJS}

fclean: clean
	$(MAKE) fclean -C ${P_LIBFT}
	${RM} ${NAME}


re: fclean all

.PHONY: all clean fclean re