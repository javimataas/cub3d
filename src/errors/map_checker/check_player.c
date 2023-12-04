/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:24:48 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/02 16:51:24 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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
				game->map->player_pos.x = j;
				game->map->player_pos.y = i;
				player++;
			}
		}
	}
	if (player != 1)
		ft_error(game, ERR_NO_PLAYER);
	return (1);
}