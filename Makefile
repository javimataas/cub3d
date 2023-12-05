# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 19:23:22 by jmatas-p          #+#    #+#              #
#    Updated: 2023/12/05 18:27:40 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN		=	\033[0;32m
YELLOW		=	\033[0;93m
FYELLOW		=	\033[38;5;154m
BLUE		=	\033[0;96m
PURPLE		=	\033[0;95m
PINK		=	\033[0;91m
RED			=	\033[0;31m
END			=	\033[0m

# Libreries
HDRS		= 	includes

LIBFT		=	libft/libft.a
MLX42		=	MLX42/libmlx42.a

CFLAGS		=	-Wall -Wextra -Werror
GLFW_FLAGS	=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

NAME	=	cub3d

SRC		=	src/main.c \
			src/errors/error.c src/errors/map_checker/extensions_checker.c src/errors/map_checker/check_walls.c src/errors/map_checker/check_utils.c src/errors/map_checker/check_player.c \
			src/init_structs/init.c src/init_structs/map/init_map_texts.c src/init_structs/map/init_map.c src/init_structs/map/init_utils.c src/init_structs/map/convert_color.c \
			src/utils/print_utils.c src/hooks/hooks.c src/utils/clean.c \
			src/render/textures.c src/render/minimap/minimap.c \

OBJ		=	$(SRC:.c=.o)


.c.o:
			@gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME):	$(LIBFT) $(MLX42) $(OBJ)
			@gcc $(CFLAGS) $(OBJ) -I $(HDRS) $(LIBFT) $(MLX42) $(GLFW_FLAGS) -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled successfully$(END)"

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
			@echo "$(GREEN)All clear$(END)"

re:			fclean all

norminette:	
			@echo "$(YELLOW)Norminette libft.$(END)"
			@norminette ./libft
			@echo "$(YELLOW)Norminette minishell.$(END)"
			@norminette ./includes
			@norminette ./src

.PHONY: all clean fclean re norminette
