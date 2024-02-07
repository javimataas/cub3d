/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:59:07 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/07 18:57:27 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_move_up(t_game *game, int *y, int *x, int *moved)
{
	int	counter;

	counter = 0;
	while (*y >= 0 && game->map->map[*y][*x] && counter < 12)
	{
		(*y)--;
		counter++;
	}
	if (counter == 12)
	{
		while (*y >= 0 && game->map->map[*y][*x])
		{
			(*y)--;
			(*moved)++;
		}
		(*moved) *= -1;
	}
	else
	{
		while (counter < 12)
		{
			(*moved)++;
			counter++;
		}
	}
}

void	ft_move_left(t_game *game, int *y, int *x, int *moved)
{
	int	counter;

	counter = 0;
	while (*x >= 0 && game->map->map[*y][*x] && counter < 12)
	{
		(*x)--;
		counter++;
	}
	if (counter == 12)
	{
		while (*x >= 0 && game->map->map[*y][*x])
		{
			(*x)--;
			(*moved)++;
		}
		(*moved) *= -1;
	}
	else
	{
		while (counter < 12)
		{
			(*moved)++;
			counter++;
		}
	}
}

int	ft_pos_map(t_game *game, int letter, int moving)
{
	int	x;
	int	y;
	int	moved;

	x = game->map->player_pos.x;
	y = game->map->player_pos.y;
	if (moving)
	{
		x = (int)game->player->minimap.x / TSIZE_3D;
		y = (int)game->player->minimap.y / TSIZE_3D;
	}
	moved = 0;
	if (letter == 1)
		ft_move_up(game, &y, &x, &moved);
	else if (letter == 0)
		ft_move_left(game, &y, &x, &moved);
	return (moved * 10);
}

void	ft_block_loop(int y, int *ry)
{
	int	n;
	int	i;

	i = -1;
	while (++i <= y)
	{
		n = -1;
		while (++n < 10)
			(*ry)++;
	}
}
