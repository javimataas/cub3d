/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:32:01 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/06 18:20:59 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	ft_paint(t_game *game, int y, int x, int color)
// {
// 	int	i;
// 	int	n;

// 	i = -1;
// 	while ((y + (++i)) < (y + TSIZE_2D))
// 	{
// 		n = -1;
// 		while ((x + (++n)) < (x + TSIZE_2D))
// 			mlx_put_pixel(game->map->minimap, x + n, y + i, color);
// 	}
// }

int	ft_check_wall(float x, float y, t_game *game)
{
	int	i;
	int	j;

	j = x / TSIZE_3D;
	i = y / TSIZE_3D;
	printf("player tile: [%d][%d]\n", i, j);
	printf("map tile: [%c]\n", game->map->map[i][j]);
	if (y < 0 || x < 0)
		return (0);
	if (game->map->map[i][j] == '1')
		return (0);
	return (1);
}
