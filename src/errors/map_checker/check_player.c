/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:24:48 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/30 18:00:08 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

double	ft_get_angle(char c)
{
	if (c == 'N')
		return (90);
	else if (c == 'S')
		return (270);
	else if (c == 'E')
		return (0);
	else if (c == 'W')
		return (180);
	return (0);
}

int	ft_check_player(t_game *game)
{
	int		i;
	int		j;
	int		player;

	i = -1;
	player = 0;
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (ft_strchr("NSEW", game->map->map[i][j]))
			{
				game->player->angrot = ft_radianes(ft_get_angle(game->map->map[i][j]));
				game->map->player_pos.x = j;
				game->player->minimap.x = j;
				game->map->player_pos.y = i;
				game->player->minimap.y = i;
				player++;
			}
		}
	}
	if (player != 1)
		ft_error(game, ERR_NO_PLAYER);
	return (1);
}
