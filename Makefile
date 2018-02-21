# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 13:19:05 by mrudyk            #+#    #+#              #
#    Updated: 2018/01/16 15:38:08 by mrudyk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, compile, clean, fclean, re

NAME = fdf
SRC = ft_fdf.c read_maps.c ft_draw.c ft_atoi_base.c ft_spin.c ft_menu_help.c ft_key_button.c ft_draw_all.c 
INC_LIBFT = ./libft/includes
CC = gcc
FLAG = -Wall -Wextra -Werror 
MLX_LINK = -lmlx -framework OpenGL -framework AppKit -L libft/ -lft
OBJ = $(subst .c, .o, $(SRC))

all: compile

compile:
	make -C ./libft/
	@$(CC) $(FLAG) -o $(NAME) $(SRC) -I $(INC_LIBFT) $(MLX_LINK)
	@echo "Compiling" [ $(NAME) ]

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean:
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
