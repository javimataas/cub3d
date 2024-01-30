/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:53:48 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/08 19:11:19 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_paint_line_x(t_game *game, int y, int x, int color)
{
	int	n;

	n = -1;
	while ((x + (++n)) < (x + TSIZE_2D))
		mlx_put_pixel(game->map->minimap, x + n, y, color);
}

void	ft_paint_line_y(t_game *game, int y, int x, int color)
{
	int	n;

	n = -1;
	while ((y + (++n)) < (y + TSIZE_2D))
		mlx_put_pixel(game->map->minimap, x, y + n, color);
}

t_coord	ft_paint_min(t_game *game, int y, int x, int color)
{
	int	i;
	int	n;
	int	ry;
	int	rx;
	t_coord	coord;

	i = -1;
	ry = 0;
	while (++i <= y)
	{
		n = -1;
		while (++n != TSIZE_2D)
			ry++;
	}
	i = -1;
	rx = 0;
	while (++i <= x)
	{
		n = -1;
		while (++n != TSIZE_2D)
			rx++;
	}
	i = -1;
	coord.x = rx;
	coord.y = ry;
	while ((ry + (++i)) < (ry + TSIZE_2D))
	{
		n = -1;
		while ((rx + (++n)) < (rx + TSIZE_2D))
			mlx_put_pixel(game->map->minimap, rx + n, ry + i, color);
	}
	return (coord);
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
				ft_paint_min(game, y, x, 0x00000000);
			else if (ft_strchr("NSEW", game->map->map[y][x]))
				game->player->minimap = ft_paint_min(game, y, x, 0xFF0000FF);
			x++;
		}
		y++;
	}
}
