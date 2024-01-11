/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:06:53 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/11 16:30:10 by jariza-o         ###   ########.fr       */
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
# include <math.h>


# define MV_SPEED	3

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
	int					color;
	mlx_image_t			*image;
	struct s_textures	*prev;
	struct s_textures	*next;
}				t_textures;

typedef struct s_map
{
	mlx_image_t	*img;
	t_coord		player_pos;
	int			start_map;
	char		**map;
	mlx_image_t	*minimap;
	t_textures	*texts;
}				t_map;

typedef struct s_player
{
	t_coord	minimap;
	t_coord	p_down_left;
	t_coord	p_up_right;
	t_coord	p_down_right;
	double	angrot;
}				t_player;

typedef struct s_game
{
	char		**file;
	mlx_t		*mlx;
	t_map		*map;
	t_player	*player;
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
void		ft_pixel(t_game *game);

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
int			ft_check_file(char *file);
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


/* TEXTURES */
void		ft_load_textures(t_game *game);

/* MAP */
/* Minimap */
t_coord		ft_paint_min(t_game *game, int y, int x, uint32_t color);
void		ft_paint_line_x(t_game *game, int y, int x, int color);
void		ft_paint_line_y(t_game *game, int y, int x, int color);
void		ft_init_minimap(t_game *game);
void		ft_background_minimap(t_game *game);
void		ft_paint_minimap(t_game *game);
int			ft_check_minimap_colision_x(t_game *game, int y, int x, char letter);
void		ft_calc_coords(t_player *player);
int			ft_colision(t_game *game, t_player *new_coord);
int			ft_front_colision(t_game *game, t_player *new_coord);
int			ft_back_colision(t_game *game, t_player *new_coord);
int			ft_right_colision(t_game *game, t_player *new_coord);
int			ft_left_colision(t_game *game, t_player *new_coord);
// int			ft_check_minimap_colision_y(t_game *game, int y, int x);

/* Floor and Cloud */
void		ft_init_colormap(t_game *game);

/* Hooks */
void		ft_init_hooks(mlx_key_data_t keydata, void *param);
void		escape_hook(t_game *game);
void		hook_screen(int32_t width, int32_t height, void *param);

/* UTILS */
/* Free functions */
void		ft_clear(t_game *game);

/* Print Functions */
void		ft_print_texts(t_game game);
void		ft_print_map(t_game *game);

/* Convert grades to radianes */
double	ft_radianes(double angolugiro);

#endif