/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:24:48 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/29 22:33:08 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

double	ft_get_angle(char c)
{
	if (c == 'N')
		return (0);
	else if (c == 'S')
		return (180);
	else if (c == 'E')
		return (270);
	else if (c == 'W')
		return (90);
	return (0);
}

void	ft_minimap_player(t_game *game)
{
	game->player->minimap.x = game->player->player_pos.x * 10;
	game->player->minimap.y = game->player->player_pos.y * 10;
	game->player->minimap_rup.x = game->player->minimap.x + 10;
	game->player->minimap_rup.y = game->player->minimap.y;
	game->player->minimap_ldown.x = game->player->minimap.x;
	game->player->minimap_rup.y = game->player->minimap.y + 10;
	game->player->minimap_rdown.x = game->player->minimap.x + 10;
	game->player->minimap_rdown.y = game->player->minimap.y + 10;
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
				game->player->angrot = ft_get_angle(game->map->map[i][j]);
				game->player->player_pos.x = j;
				game->player->player_pos.y = i;
				ft_minimap_player(game);
				player++;
			}
		}
	}
	if (player != 1)
		ft_error(game, ERR_NO_PLAYER);
	return (1);
}
