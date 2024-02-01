/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:06:53 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/01 16:43:02 by jariza-o         ###   ########.fr       */
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

# define PI			3.14159
# define S_HEIGHT	1080
# define S_WIDTH	1920
# define MV_SPEED	1
# define TSIZE_2D	10
# define TSIZE_3D	10
# define DEPTH		1.0
# define DEF		8

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
	ERR_COLOR_FAIL,
	ERR_WRNG_ID
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
	t_textures	*texts;
	int			height;
	int			width;
}				t_map;

typedef struct s_minimap
{
	mlx_image_t	*img;
	mlx_image_t	*player;
	t_coord		img_paint; //LO HE AÑADIDO Y AHORA NO LO USO
}				t_minimap;

typedef struct s_player
{
	t_coord	minimap;
	double	angrot;
}				t_player;

typedef struct s_rays
{
	float				ang;
	double				dist;
	t_coord				hit;
	char				dir;
	long unsigned int	color;
}				t_rays;

typedef struct s_game
{
	char				**file;
	mlx_t				*mlx;
	t_map				*map;
	t_minimap			*minimap;
	t_player			*player;
	t_rays				*rays;
	t_coord				start;
	t_coord				end;
	t_coord				pix;
	mlx_image_t			*img3d;
	mlx_image_t			*img2d;
	mlx_texture_t		**textures;
	int					h_line;
	int					pov_ang;
	int					final_s_width;
	float				ty_step;
	long unsigned int	c_pix;
}					t_game;

/* Init */
/* Init Struct */
t_game			*ft_init_map(char *path);

/* Create t_textures */
void			ft_init_map_textures(t_game *game);
t_textures		*ft_lstnew_texts(void);
t_textures		*ft_lstlast_texts(t_textures *lst);
void			ft_lstadd_back_texts(t_textures **lst, t_textures *new);

/* Load Textures in Struct */
void			ft_load_struct(t_game *game);
void			ft_select_texts(t_game *game, char *line);
void			ft_pixel(t_game *game);

/* Load Map */
void			ft_reserve_map(t_game *game);
void			ft_load_map(t_game *game);

/* Init Utils */
int				ft_is_empty(char *line);
int				ft_is_texts(char *line);
int				ft_check_texts(t_game *game);
char			**ft_read_file(char *path);
int				ft_reserve_matrix(char *path);

/* Map Checker */
void			ft_error(t_game *game, int error);

/* Extension Checker */
int				ft_check_file(char *file);
int				ft_check_cub(char *file);
int				ft_check_png(char *file);

/* Check Walls */
int				ft_check_walls(t_game *game, char **map);

/* Check Player */
int				ft_check_player(t_game *game);

/* Checker Utils */
int				ft_get_len_x(char **map);
int				ft_get_len_y(char **map);
char			**ft_add_extra_rows(char **map);
t_coord			ft_get_player_coord(char **map);
int				ft_contains_str(char *str, char *container);

/* TEXTURES */
void			ft_load_textures(t_game *game);

/* MAP */
/* Minimap */
void			ft_init_minimap(t_game *game);
void			ft_paint_player(t_game *game);
void			ft_paint_minimap(t_game *game, int img);
int				ft_pos_map(t_game *game, int letter);
int				ft_calc_size(t_game *game, int letter);
void			ft_paint_elements(t_game *game);

/* Floor and Cloud */
void			ft_init_colormap(t_game *game);

/* Hooks */
void			ft_init_hooks(mlx_key_data_t keydata, void *param);
void			escape_hook(t_game *game);
void			hook_screen(int32_t width, int32_t height, void *param);
void			ft_update(void *param);

/* Move Hooks */
void			ft_paint(t_game *game, int y, int x, int color);
void			w_key(t_game *game);
void			s_key(t_game *game);
void			a_key(t_game *game);
void			d_key(t_game *game);
void			my_scrollhook(double xdelta, double ydelta, void* param);

/* Hooks Utils */
void			ft_paint(t_game *game, int y, int x, int color);
int				ft_check_wall(float x, float y, t_game *game);

/* UTILS */
/* Free functions */
void			ft_clear(t_game *game);

/* Print Functions */
void			ft_print_texts(t_game game);
void			ft_print_map(t_game *game);

/* Convert grades to radianes */
double			ft_radianes(double angolugiro);

/* POV (3D) */
int				ft_display_pov(t_game *game);

/* C_Pixel */
unsigned long	ft_get_pix_color(mlx_texture_t *text, int x_tex, int y_tex);
void			ft_fish_eye(t_game *game, int i);

/* Rays */
void			ft_rays(t_game *game);

/* Rays Utils */
void			ft_check_h(t_game *game, t_coord *start, t_coord *end, int i);
void			ft_check_v(t_game *game, t_coord *start, t_coord *end, int i);

#endif