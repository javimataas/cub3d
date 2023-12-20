/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:40:11 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/20 17:49:02 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_inc_step(t_coord step, t_coord *end, int *k)
{
	end->y += step.y;
	end->x += step.x;
	(*k)++;
}

t_coord	ft_red_coord(t_coord c)
{
	c.x = c.x / TILESIZE_3D * TILESIZE_2D;
	c.y = c.y / TILESIZE_3D * TILESIZE_2D;
	return (c);
}

void	ft_draw_line(t_game *game, mlx_image_t *img, t_coord start, t_coord end)
{
	float	d_y;
	float	d_x;
	int		len;

	d_y = end.y - start.y;
	d_x = end.x - start.x;
	len = sqrt((d_y * d_y) + (d_x * d_x)) + 1;
	d_y /= len;
	d_x /= len;
	while (len)
	{
		if (((start.x < (game->map->width * TILESIZE_3D) - 1) && start.x > 0)
			&& (start.y < ((game->map->height * TILESIZE_3D) - 1) && start.y > 0))
			mlx_put_pixel(img, start.x, start.y, 0x00000000);
		start.y += d_y;
		start.x += d_x;
		--len;
	}
}
