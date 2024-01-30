/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:32:01 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/30 22:51:56 by jariza-o         ###   ########.fr       */
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
	if (game->map->map[i][j] == '1')
		return (0);
	return (1);
}
