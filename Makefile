# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:56:20 by jmatas-p          #+#    #+#              #
#    Updated: 2024/02/09 15:04:23 by jariza-o         ###   ########.fr        #
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

NAME		=	cub3D
NAME_BONUS	=	cub3D_bonus

SRC		=	src/main.c \
			src/errors/error.c src/errors/map_checker/extensions_checker.c src/errors/map_checker/check_walls.c src/errors/map_checker/check_walls_2.c  \
			src/errors/map_checker/check_utils.c src/errors/map_checker/check_player.c src/init_structs/load_texts.c\
			src/init_structs/init.c src/init_structs/map/init_map_texts.c src/init_structs/map/init_map.c src/init_structs/map/init_utils.c src/init_structs/map/convert_color.c \
			src/utils/print_utils.c src/utils/clean.c src/utils/radianes.c src/render/textures.c \
			src/render/map/map.c src/hooks/hooks.c src/hooks/move_hooks.c src/hooks/hooks_utils.c \
			src/hooks/update.c \
			src/rays/pov.c src/rays/c_pixel.c src/rays/rays.c src/rays/rays_utils.c \
			src/init_structs/map/init_map_2.c \

SRC_BONUS	=	src_bonus/main_bonus.c \
			src_bonus/errors/error_bonus.c src_bonus/errors/map_checker/extensions_checker_bonus.c src_bonus/errors/map_checker/check_walls_bonus.c src_bonus/errors/map_checker/check_walls_2_bonus.c  \
			src_bonus/errors/map_checker/check_utils_bonus.c src_bonus/errors/map_checker/check_player_bonus.c src_bonus/init_structs/load_texts_bonus.c\
			src_bonus/init_structs/init_bonus.c src_bonus/init_structs/map/init_map_texts_bonus.c src_bonus/init_structs/map/init_map_bonus.c src_bonus/init_structs/map/init_utils_bonus.c src_bonus/init_structs/map/convert_color_bonus.c \
			src_bonus/utils/print_utils_bonus.c src_bonus/utils/clean_bonus.c src_bonus/utils/radianes_bonus.c src_bonus/render/textures_bonus.c src_bonus/render/minimap/minimap_bonus.c \
			src_bonus/render/map/map_bonus.c src_bonus/render/minimap/player_bonus.c src_bonus/hooks/hooks_bonus.c src_bonus/hooks/move_hooks_bonus.c src_bonus/hooks/hooks_utils_bonus.c \
			src_bonus/hooks/mouse_bonus.c src_bonus/hooks/update_bonus.c src_bonus/render/animations_bonus.c src_bonus/render/minimap/pos_map_bonus.c \
			src_bonus/rays/pov_bonus.c src_bonus/rays/c_pixel_bonus.c src_bonus/rays/rays_bonus.c src_bonus/rays/rays_utils_bonus.c \
			src_bonus/init_structs/map/init_map_2_bonus.c \

OBJ		=	$(SRC:.c=.o)

OBJT_BONUS = $(SRC_BONUS:.c=.o)

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
clean_bonus:
			@make clean -C libft
			@make clean -C MLX42/
			@rm -f $(OBJT_BONUS)

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft
			@make fclean -C MLX42/
			@echo "$(GREEN)All clear$(END)"
fclean_bonus:		clean
			@rm -f $(NAME_BONUS)
			@make fclean -C libft
			@make fclean -C MLX42/
			@echo "$(GREEN)All clear$(END)"

bonus:		fclean fclean_bonus $(NAME_BONUS)
ifeq ($(shell uname -s), Darwin)
$(NAME_BONUS):	$(LIBFT) $(MLX42) $(OBJT_BONUS)
			@gcc $(CFLAGS) $(OBJT_BONUS) -I $(HDRS) $(LIBFT) $(MLX42) $(GLFW_FLAGS) -o $(NAME_BONUS)
			@echo "$(GREEN)$(NAME) compiled successfully$(END)"
else ifeq ($(shell uname -s), Linux)
$(NAME_BONUS):	$(LIBFT) $(MLX42) $(OBJT_BONUS)
			@gcc $(CFLAGS) $(OBJT_BONUS) -I $(HDRS) $(LIBFT) $(MLX42) $(LINUX_DEP) -o $(NAME_BONUS)
			@echo "$(GREEN)$(NAME) compiled successfully$(END)"
endif

re:			fclean fclean_bonus all

re_bonus:	fclean fclean_bonus bonus

norminette:	
			@echo "$(YELLOW)Norminette libft.$(END)"
			@norminette ./libft
			@echo "$(YELLOW)Norminette cub3d.$(END)"
			@norminette ./includes
			@norminette ./src
			@echo "$(YELLOW)Norminette cub3d_bonus.$(END)"
			@norminette ./includes_bonus
			@norminette ./src_bonus

.PHONY: all clean clean_bonus fclean fclean_bonus bonus re re_bonus norminette
