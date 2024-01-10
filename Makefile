# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 19:23:22 by jmatas-p          #+#    #+#              #
#    Updated: 2024/01/10 19:34:56 by jmatas-p         ###   ########.fr        #
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
LINUX_DEP	=	$(PWD)/MLX42/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

NAME	=	cub3d

SRC		=	src/main.c \
			src/errors/error.c src/errors/map_checker/extensions_checker.c src/errors/map_checker/check_walls.c src/errors/map_checker/check_utils.c src/errors/map_checker/check_player.c \
			src/init_structs/init.c src/init_structs/map/init_map_texts.c src/init_structs/map/init_map.c src/init_structs/map/init_utils.c src/init_structs/map/convert_color.c \
			src/utils/print_utils.c src/utils/clean.c src/utils/radianes.c\
			src/render/textures.c src/render/minimap/minimap.c src/render/minimap/walls.c src/render/map/map.c \
			src/hooks/hooks.c src/rays/pov.c src/rays/c_pixel.c src/rays/rays.c \

OBJ		=	$(SRC:.c=.o)

.c.o:
			@gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)
ifeq ($(shell uname -s), Darwin)
$(NAME):	$(LIBFT) $(MLX42) $(OBJ)
			@gcc $(CFLAGS) $(OBJ) -I $(HDRS) $(LIBFT) $(MLX42) $(GLFW_FLAGS) -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled successfully$(END)"
else ifeq ($(shell uname -s), Linux)
$(NAME):	$(LIBFT) $(MLX42) $(OBJ)
			@gcc $(CFLAGS) $(OBJ) -I $(HDRS) $(LIBFT) $(MLX42) $(LINUX_DEP) -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled successfully$(END)"
endif

$(LIBFT):
			@make -C libft

$(MLX42):
			@make -C MLX42/

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@make clean -C libft
			@make clean -C MLX42/
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft
			@make fclean -C MLX42/
			@echo "$(GREEN)All clear$(END)"

re:			fclean all

norminette:	
			@echo "$(YELLOW)Norminette libft.$(END)"
			@norminette ./libft
			@echo "$(YELLOW)Norminette minishell.$(END)"
			@norminette ./includes
			@norminette ./src

.PHONY: all clean fclean re norminette
