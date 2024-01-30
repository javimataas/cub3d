/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:25:02 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/08 19:12:24 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_check_minimap_colision_x(t_game *game, int y, int x, char letter)
{
	int	ry;
	int	aux_ry;
	int	rx;
	int	i;
	int	n;
	int	s = 1; // tamaño del personaje
	i = -1;
	while (game->map->map[++i])
	{
		n = -1;
		while (game->map->map[i][++n])
		{
			aux_ry = i * TSIZE_2D;
			if (letter == 'w') 
				aux_ry += TSIZE_2D;
			ry = aux_ry;
			while (ry < (aux_ry + TSIZE_2D))
			{
				rx = n * TSIZE_2D;
				while (rx < (n * TSIZE_2D + TSIZE_2D))
				{
					if ((ry == y - s/2 || ry == y + s/2) && (rx == x - s/2 || rx == x + s/2) && game->map->map[i][n] == '1')
						return (0);
					rx++;
				}
				ry++;
			}
		}
	}
	return (1);
}
// int	ft_check_minimap_colision_y(t_game *game, int y, int x)
// {
// 	int	ry;
// 	int	rx;
// 	int	i;
// 	int	n;
// 	i = -1;
// 	while (game->map->map[++i])
// 	{
// 		ry = (i * TSIZE_2D) + TSIZE_2D;
// 		if (ry == y)
// 		{
// 			n = -1;
// 			while (game->map->map[i][++n])
// 			{
// 				rx = x * TSIZE_2D;
// 				if (rx >= (x) && rx <= (x + TSIZE_2D))
// 					if (game->map->map[i][n] == '1')
// 						return (0);
// 			}
// 		}
// 	}
// 	return (1);
// }
