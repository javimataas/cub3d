/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:06:53 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/02 16:52:03 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

enum			e_datatype
{
	ERR_WRNG_ARGS,
	ERR_WRNG_EXT,
	ERR_MLLC_FAIL,
	ERR_DUP_TEXTS,
	ERR_MISS_TEXTS,
	ERR_EMPT_TEXTS,
	ERR_MLX_FAIL,
	ERR_MAP_FAIL,
	ERR_NO_PLAYER,
	ERR_PNG_FAIL,
	ERR_COLOR_FAIL
};

typedef struct s_coord
{
	float	x;
	float	y;
}				t_coord;

typedef struct s_textures
{
	char				*id;
	char				*path;
	mlx_image_t			*image;
	struct s_textures	*prev;
	struct s_textures	*next;
}				t_textures;

typedef struct s_minimap
{
	mlx_image_t	*img;
}				t_minimap;

typedef struct s_map
{
	mlx_image_t	*img;
	t_coord		player_pos;
	int			start_map;
	char		**map;
	t_minimap	*minimap;
	t_textures	*texts;
}				t_map;

typedef struct s_game
{
	char		**file;
	mlx_t		*mlx;
	t_map		*map;
}				t_game;

/* Init */
/* Init Struct */
t_game		*ft_init_map(char *path);

/* Create t_textures */
void		ft_init_map_textures(t_game *game);
t_textures	*ft_lstnew_texts(void);
t_textures	*ft_lstlast_texts(t_textures *lst);
void		ft_lstadd_back_texts(t_textures **lst, t_textures *new);

/* Load Textures in Struct */
void		ft_load_struct(t_game *game);
void		ft_select_texts(t_game *game, char *line);

/* Load Map */
void		ft_reserve_map(t_game *game);
void		ft_load_map(t_game *game);

/* Init Utils */
int			ft_is_empty(char *line);
int			ft_is_texts(char *line);
int			ft_check_texts(t_game *game);
char		**ft_read_file(char *path);
int			ft_reserve_matrix(char *path);

/* Map Checker */
void		ft_error(t_game *game, int error);

/* Extension Checker */
int			ft_check_cub(char *file);
int			ft_check_png(char *file);

/* Check Walls */
int			ft_check_walls(t_game *game, char **map);

/* Check Player */
int			ft_check_player(t_game *game);

/* Checker Utils */
int			ft_get_len_x(char **map);
int			ft_get_len_y(char **map);
char		**ft_add_extra_rows(char **map);
t_coord		ft_get_player_coord(char **map);
int			ft_contains_str(char *str, char *container);

/* UTILS */
/* Free functions */
void		ft_clear(t_game *game);

/* Print Functions */
void		ft_print_texts(t_game game);
void		ft_print_map(t_game *game);

/* TEXTURES */
void		ft_load_textures(t_game *game);

/* MAP */
/* Minimap */
void		ft_init_minimap(t_game *game);
void		ft_paint_minimap(t_game *game);

/* Hooks */
void		escape_hook(mlx_key_data_t keydata, void *param);
void		hook_screen(int32_t width, int32_t height, void *param);

#endif