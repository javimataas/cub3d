/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:53:48 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/04 19:35:34 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_init_minimap(t_game *game)
{
	game->map->minimap = mlx_new_image(game->mlx, 331, 331);
	if (!game->map->minimap)
		ft_error(game, ERR_MLX_FAIL);
	if (mlx_image_to_window(game->mlx, game->map->minimap , 0, 0) < 0)
		ft_error(game, ERR_MLX_FAIL);
	ft_background_minimap(game);
	ft_walls_minimap(game);
}

void	ft_background_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < 331)
	{
		x = 0;
		while (x < 331)
		{
			mlx_put_pixel(game->map->minimap, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

void	ft_walls_minimap(t_game *game)
{
	int	y;
	int	x;
	int	py;
	int	px;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '1')
			{
				py = 0;
				while (py < 63)
				{
					px = 0;
					while (px < 63)
					{
						mlx_put_pixel(game->map->minimap, x + py, y + px, 0x000000);
						px++;
					}
					py++;
				}
			}
			else
			{
				py = 0;
				while (py < 63)
				{
					px = 0;
					while (px < 63)
					{
						mlx_put_pixel(game->map->minimap, x + py, y + px, 0xFFFFFFFF);
						px++;
					}
					py++;
				}
			}
			x++;
		}
		y++;
	}
}
