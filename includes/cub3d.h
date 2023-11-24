/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:06:53 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/24 16:55:49 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "map_checker.h"

enum e_datatype
{
	ERR_WRNG_ARGS,
	ERR_WRNG_EXT
};

typedef struct s_textures
{
	char		*id;
	char		*path;
	t_textures	*prev;
	t_textures	*next;
}	t_textures;


typedef struct s_map
{
	char		**map;
	t_textures	*texts;
}	t_map;

typedef struct s_game
{
	mlx_t	*mlx;
	t_map	*map;
}	t_game;

#endif