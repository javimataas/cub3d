/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:24:35 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/07 17:54:32 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_paint_player(t_game *game)
{
	int	x;
	int	y;

	game->minimap->player = mlx_new_image(game->mlx, 10, 10);
	if (!game->minimap->player)
		ft_error(game, ERR_MLX_FAIL);
	if (mlx_image_to_window(game->mlx, game->minimap->player, 120, 120) < 0)
		ft_error(game, ERR_MLX_FAIL);
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			mlx_put_pixel(game->minimap->player, x, y, 0xFF0000FF);
			x++;
		}
		y++;
	}
	game->minimap->player->instances[0].z = 2;
}
