/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:25:02 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/13 16:01:31 by jariza-o         ###   ########.fr       */
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
			aux_ry = i * 14;
			if (letter == 'w') 
				aux_ry += 14;
			ry = aux_ry;
			while (ry < (aux_ry + 14))
			{
				rx = n * 14;
				while (rx < (n * 14 + 14))
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
// 		ry = (i * 14) + 14;
// 		if (ry == y)
// 		{
// 			n = -1;
// 			while (game->map->map[i][++n])
// 			{
// 				rx = x * 14;
// 				if (rx >= (x) && rx <= (x + 14))
// 					if (game->map->map[i][n] == '1')
// 						return (0);
// 			}
// 		}
// 	}
// 	return (1);
// }
