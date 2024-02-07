/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:53:48 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/07 16:18:43 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_coord	ft_paint_min(t_game *game, int y, int x, int color)
{
	int		i;
	int		n;
	int		ry;
	int		rx;
	t_coord	coord;

	i = -1;
	ry = 0;
	while (++i <= y)
	{
		n = -1;
		while (++n != 10)
			ry++;
	}
	i = -1;
	rx = 0;
	while (++i <= x)
	{
		n = -1;
		while (++n != 10)
			rx++;
	}
	i = -1;
	coord.x = rx;
	coord.y = ry;
	while ((ry + (++i)) < (ry + 10))
	{
		n = -1;
		while ((rx + (++n)) < (rx + 10))
			mlx_put_pixel(game->minimap->img, rx + n, ry + i, color);
	}
	return (coord);
}

void	ft_paint_elements(t_game *game)
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
				ft_paint_min(game, y, x, 0x000000FF);
			else if (game->map->map[y][x] == '0'
				|| ft_strchr("NSEW", game->map->map[y][x]))
				ft_paint_min(game, y, x, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

int	ft_calc_size(t_game *game, int letter)
{
	int	size;
	int	long_line;
	int	y;

	size = 0;
	long_line = 0;
	y = 0;
	if (letter == 0)
		while (game->map->map[long_line])
			long_line++;
	else if (letter == 1)
	{
		while (game->map->map[y])
		{
			size = 0;
			while (game->map->map[y][size])
				size++;
			if (long_line < size)
				long_line = size;
			y++;
		}
	}
	return ((long_line * 10) + 10); //añado +10 para que vaya bien, revisarlo bien
}

int	ft_pos_map(t_game *game, int letter, int moving)
{
	int	y;
	int	x;
	int	counter;
	int	moved;

	y = game->map->player_pos.y;
	x = game->map->player_pos.x;
	if (moving)
	{
		y = (int)game->player->minimap.y / TSIZE_3D;
		x = (int)game->player->minimap.x / TSIZE_3D;
	}
	counter = 0;
	moved = 0;
	if (letter == 1)
	{
		while (y >= 0 && game->map->map[y][x] && counter < 12)
		{
			y--;
			counter++;
		}
		if (counter == 12)
		{
			while (y >= 0 && game->map->map[y][x])
			{
				y--;
				moved++;
			}
			moved *= -1;
		}
		else
		{
			while (counter < 12)
			{
				moved++;
				counter++;
			}
		}
	}
	else if (letter == 0)
	{
		while (x >= 0 && game->map->map[y][x] && counter < 12)
		{
			x--;
			counter++;
		}
		if (counter == 12)
		{
			while (x >= 0 && game->map->map[y][x])
			{
				x--;
				moved++;
			}
			moved *= -1;
		}
		else
		{
			while (counter < 12)
			{
				moved++;
				counter++;
			}
		}
	}
	return (moved * 10);
}

void	ft_paint_minimap(t_game *game, int img, int moving)
{
	if (img)
		mlx_delete_image(game->mlx, game->minimap->img);
	game->minimap->img = mlx_new_image(game->mlx, ft_calc_size(game, 1), ft_calc_size(game, 0));
	if (!moving)
	{
		if (mlx_image_to_window(game->mlx, game->minimap->img, ft_pos_map(game, 0, 0), ft_pos_map(game, 1, 0)) < 0)
			ft_error(game, ERR_MLX_FAIL);
	}
	else if (moving)
		if (mlx_image_to_window(game->mlx, game->minimap->img, ft_pos_map(game, 0, 1), ft_pos_map(game, 1, 1)) < 0)
			ft_error(game, ERR_MLX_FAIL);
	ft_paint_elements(game);
	game->minimap->img->instances[0].z = -1;
}

void	ft_init_minimap(t_game *game)
{
	ft_paint_player(game);
	ft_paint_minimap(game, 0, 0);
}
