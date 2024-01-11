/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:24:35 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/11 18:40:52 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void    ft_paint_player(t_game *game)
{
	int x;
	int y;
	
	game->minimap->player = mlx_new_image(game->mlx, 250, 250);
	if (!game->minimap->player)
		ft_error(game, ERR_MLX_FAIL);
	if (mlx_image_to_window(game->mlx, game->minimap->player, 0, 0) < 0)
		ft_error(game, ERR_MLX_FAIL);
	y = 120;
	while (y <= 130)
	{
		x = 120;
		while (x <= 130)
		{
			mlx_put_pixel(game->minimap->player, x, y, 0xFF0000FF);
			x++;
		}
		y++;
	}
	game->minimap->player->instances[0].z = 1;
}
