/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:53:48 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/09 19:31:45 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_paint(t_game *game, int y, int x, int color)
{
	int	i;
	int	n;
	int	ry;
	int	rx;

	i = -1;
	ry = 0;
	while (++i <= y)
	{
		n = -1;
		while (++n != 14)
			ry++;
	}
	i = -1;
	rx = 0;
	while (++i <= x)
	{
		n = -1;
		while (++n != 14)
			rx++;
	}
	i = -1;
	while ((ry + (++i)) < (ry + 14))
	{
		n = -1;
		while ((rx + (++n)) < (rx + 14))
			mlx_put_pixel(game->map->minimap, rx + n, ry + i, color);
	}
}

void	ft_init_minimap(t_game *game)
{
	game->map->minimap = mlx_new_image(game->mlx, 662, 331);
	if (!game->map->minimap)
		ft_error(game, ERR_MLX_FAIL);
	if (mlx_image_to_window(game->mlx, game->map->minimap, 0, 0) < 0)
		ft_error(game, ERR_MLX_FAIL);
	ft_background_minimap(game);
	ft_paint_minimap(game);
}

void	ft_background_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < 331)
	{
		x = 0;
		while (x < 662)
		{
			mlx_put_pixel(game->map->minimap, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

void	ft_paint_minimap(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '1')
				ft_paint(game, y, x, 0x00000000);
			else if (ft_strchr("NSEW", game->map->map[y][x]))
				ft_paint(game, y, x, 0xFF0000FF);
			x++;
		}
		y++;
	}
}
