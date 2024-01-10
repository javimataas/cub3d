/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:12:30 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/08 19:10:58 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_paint(t_game *game, int y, int x, int color)
{
	int	i;
	int	n;
	
	i = -1;
	while ((y + (++i)) < (y + TSIZE_2D))
	{
		n = -1;
		while ((x + (++n)) < (x + TSIZE_2D))
			mlx_put_pixel(game->map->minimap, x + n, y + i, color);
	}
}

void	w_key(t_game *game)
{
	//printf("W %f %f hola \n", game->player->minimap.y, game->player->minimap.x);
	ft_paint_line_x(game, game->player->minimap.y + TSIZE_2D, game->player->minimap.x, 0xFFFFFFFF);
	game->player->minimap.y -= 1;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFF0000FF);
}
