/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:45:33 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/13 23:08:31 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_check_void_lines(t_game *game, int y)
{
	int	x;

	y++;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] != ' ' && game->map->map[y][x] != '\n' \
			&& game->map->map[y][x] != '\t')
				ft_error(game, ERR_MAP_FAIL);
			x++;
		}
		y++;
	}
}

void	ft_check_letter(t_game *game, int *y, int *x)
{
	if (game->map->map[(*y)][(*x)] != '1' && game->map->map[(*y)][(*x)] != '0' \
	&& game->map->map[(*y)][(*x)] != ' ' && game->map->map[(*y)][(*x)] != 'N' \
	&& game->map->map[(*y)][(*x)] != 'W' && game->map->map[(*y)][(*x)] != 'S' \
	&& game->map->map[(*y)][(*x)] != 'E' && game->map->map[(*y)][(*x)] != '\n')
		ft_error(game, ERR_MAP_FAIL);
}

void	ft_check_map_symbols(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x] != '\0')
		{
			if (x == 0 && (game->map->map[y][x] == ' ' \
			|| game->map->map[y][x] == '\n' \
			|| game->map->map[y][x] == '\t' ))
			{
				while (game->map->map[y][x] != '\n' \
				&& (game->map->map[y][x] == ' ' \
				|| game->map->map[y][x] == '\t'))
					x++;
				if (game->map->map[y][x] == '\n' \
				|| game->map->map[y][x] == '\0')
					ft_check_void_lines(game, y);
			}
			ft_check_letter(game, &y, &x);
		}
	}
}
