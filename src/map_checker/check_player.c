/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:24:48 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/29 17:25:53 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_player(char **map)
{
	int		i;
	int		j;
	int		player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		ft_error(ERR_NO_PLAYER);
	return (1);
}