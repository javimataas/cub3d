/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:45:33 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/13 22:04:45 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/cub3d_bonus.h"

void	ft_check_map_symbols(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			if (game->map->map[y][x] != '1' && game->map->map[y][x] != '0' \
			&& game->map->map[y][x] != ' ' && game->map->map[y][x] != 'N' \
			&& game->map->map[y][x] != 'W' && game->map->map[y][x] != 'S' \
			&& game->map->map[y][x] != 'E' && game->map->map[y][x] != '\n')
			{
				printf("ES DISTINTO\n");
				ft_error(game, ERR_MAP_FAIL);
			}
			x++;
		}
		y++;
	}
}
