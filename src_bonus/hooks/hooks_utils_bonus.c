/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:32:01 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/08 22:11:07 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	ft_check_wall(float x, float y, t_game *game)
{
	int	i;
	int	j;

	j = x / TSIZE_3D;
	i = y / TSIZE_3D;
	if (y < 0 || x < 0)
		return (0);
	if (game->map->map[i][j] == '1')
		return (0);
	return (1);
}
