/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:24:48 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/08 22:11:27 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/cub3d_bonus.h"

double	ft_angle(char c)
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
				game->player->angrot = ft_rads(ft_angle(game->map->map[i][j]));
				game->map->player_pos.x = j;
				game->player->minimap.x = j * TSIZE_3D;
				game->map->player_pos.y = i;
				game->player->minimap.y = i * TSIZE_3D;
				player++;
			}
		}
	}
	if (player != 1)
		ft_error(game, ERR_NO_PLAYER);
	return (1);
}
