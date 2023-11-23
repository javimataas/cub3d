/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:06:53 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/23 17:43:55 by jariza-o         ###   ########.fr       */
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

typedef struct s_map
{
	char	*map_path;
	char	**textures;
	char	**map;
}	t_map;

typedef struct s_game
{
	mlx_t	*mlx;
	t_map	*s_map;
}	t_game;

#endif