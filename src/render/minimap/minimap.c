/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:53:48 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/18 17:56:28 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_paint_line_x(t_game *game, int y, int x, int color)
{
	int	n;

	n = -1;
	while ((x + (++n)) < (x + 14))
		mlx_put_pixel(game->map->minimap, x + n, y, color);
}

void	ft_paint_line_y(t_game *game, int y, int x, int color)
{
	int	n;

	n = -1;
	while ((y + (++n)) < (y + 14))
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
	coord.x = rx;
	coord.y = ry;
	while ((ry + (++i)) < (ry + 14))
	{
		n = -1;
		while ((rx + (++n)) < (rx + 14))
			mlx_put_pixel(game->map->minimap, rx + n, ry + i, color);
	}
	return (coord);
}

void	ft_calc_coords(t_player *player)
{
	player->p_down_left.y = player->minimap.y + 14;
	player->p_up_right.x = player->minimap.x + 14;
	player->p_down_right.y = player->minimap.y + 14;
	player->p_down_right.x = player->minimap.x + 14;
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
	ft_calc_coords(game->player);
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
