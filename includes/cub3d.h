/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:06:53 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/28 17:43:16 by jariza-o         ###   ########.fr       */
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
	ERR_EMPT_TEXTS
};

typedef struct s_textures
{
	char				*id;
	char				*path;
	struct s_textures	*prev;
	struct s_textures	*next;
}				t_textures;

typedef struct s_map
{
	int			start_map;
	char		**file;
	char		**map;
	t_textures	*texts;
}				t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
}				t_game;

/* INIT */
/* INIT_STRUCT */
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

/* MAP CHECHKER*/
void		ft_error(int error);
int			ft_check_extension(char *file);

/* UTILS */
/* Print Functions */
void		ft_print_texts(t_game game);
void		ft_print_map(t_game *game);

#endif