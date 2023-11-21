# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 19:23:22 by jmatas-p          #+#    #+#              #
#    Updated: 2023/11/21 18:43:01 by jmatas-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	libft/libft.a

MLX42	=	MLX42/libmlx42.a

GREEN	=	\033[0;32m

SRC		=	src/main.c src/map_checker/error.c src/map_checker/map_checker.c

OBJ		=	$(SRC:.c=.o)

NAME	=	cub3d

all:		$(NAME)

$(NAME):	$(LIBFT) $(MLX42) $(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/jmatas-p/.brew/opt/glfw/lib/" -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled successfully"

$(LIBFT):
			@make -C libft

$(MLX42):
			@make -C MLX42/

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft
			@make clean -C MLX42/
			@echo "$(GREEN)All clear"

re:			fclean all

.PHONY: all clean fclean re
