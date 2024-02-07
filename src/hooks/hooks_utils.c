/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:32:01 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/07 16:55:58 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_wall(float x, float y, t_game *game)
{
	int	i;
	int	j;

	j = x / TSIZE_3D;
	i = y / TSIZE_3D;
	printf("player tile: [%d][%d]\n", i, j);
	printf("map tile: [%c]\n", game->map->map[i][j]);
	if (y < 0 || x < 0)
		return (0);
	if (game->map->map[i][j] == '1')
		return (0);
	return (1);
}
