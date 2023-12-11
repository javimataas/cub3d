/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:12:30 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/11 18:10:42 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_paint(t_game *game, int y, int x, int color)
{
	int	i;
	int	n;
	
	i = -1;
	while ((y + (++i)) < (y + 14))
	{
		n = -1;
		while ((x + (++n)) < (x + 14))
			mlx_put_pixel(game->map->minimap, x + n, y + i, color);
	}
}

void	w_key(t_game *game)
{
	//printf("W %f %f hola \n", game->player->minimap.y, game->player->minimap.x);
	ft_paint_line_x(game, game->player->minimap.y + 14, game->player->minimap.x, 0xFFFFFFFF);
	game->player->minimap.y -= 1;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFF0000FF);
}
