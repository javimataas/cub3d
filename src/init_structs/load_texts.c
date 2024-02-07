/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:36:17 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/07 19:36:50 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_load_game_textures(t_game *game)
{
	game->textures = ft_calloc(sizeof(mlx_texture_t *), 4);
	game->textures[0] = mlx_load_png(game->map->texts->path);
	game->textures[1] = mlx_load_png(game->map->texts->next->path);
	game->textures[2] = mlx_load_png(game->map->texts->next->next->path);
	game->textures[3] = mlx_load_png(game->map->texts->next->next->next->path);
	if (game->textures[0] == NULL || game->textures[1] == NULL
		|| game->textures[2] == NULL || game->textures[3] == NULL)
		return (ft_error(game, ERR_MLX_FAIL));
}
