/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:30:24 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/17 18:14:12 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_inc_step(t_coord step, t_coord *end, int *k)
{
	(*k)++;
	end->x += step.x;
	end->y += step.y;
}

void	ft_loop_h(t_game *game, t_coord step, t_coord *end)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k < game->map->height)
	{
		if (end->y >= 0 && end->y < (TSIZE_3D * game->map->height)
			&& end->x >= 0 && end->x < (TSIZE_3D * game->map->width))
		{
			i = end->y / TSIZE_3D;
			j = end->x / TSIZE_3D;
			if (i < 0 || j < 0 || i > game->map->height || j > game->map->width
				|| game->map->map[i][j] == '1')
				break ;
			else
				ft_inc_step(step, end, &k);
		}
		else
			break ;
	}
}

void	ft_check_h(t_game *game, t_coord *start, t_coord *end, int i)
{
	t_coord	step;
	float	ray_angle;
	float	atan;

	ray_angle = game->rays[i].ang;
	atan = -1 / tan(ray_angle);
	if (ray_angle > PI)
	{
		end->y = (int)(start->y / TSIZE_3D) * TSIZE_3D + TSIZE_3D;
		end->x = ((end->y - start->y) * atan) + start->x;
		step.y = TSIZE_3D;
		step.x = step.y * atan;
	}
	if (ray_angle < PI)
	{
		end->y = (int)(start->y / TSIZE_3D) * TSIZE_3D - 0.001;
		end->x = ((end->y - start->y) * atan) + start->x;
		step.y = -TSIZE_3D;
		step.x = step.y * atan;
	}
	ft_loop_h(game, step, end);
}

void	ft_loop_v(t_game *game, t_coord step, t_coord *end)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k < game->map->width)
	{
		if (end->y >= 0 && end->y < (TSIZE_3D * game->map->height)
			&& end->x >= 0 && end->x < (TSIZE_3D * game->map->width))
		{
			i = end->y / TSIZE_3D;
			j = end->x / TSIZE_3D;
			if (i < 0 || j < 0 || i > game->map->height || j > game->map->width
				|| game->map->map[i][j] == '1')
				break ;
			else
				ft_inc_step(step, end, &k);
		}
		else
			break ;
	}
}

void	ft_check_v(t_game *game, t_coord *start, t_coord *end, int i)
{
	t_coord	step;
	float	ray_angle;
	float	ntan;

	ray_angle = game->rays[i].ang;
	ntan = -tan(ray_angle);
	if (ray_angle > (PI / 2) && ray_angle < (PI / 2 * 3))
	{
		end->x = (int)(start->x / TSIZE_3D) * TSIZE_3D - 0.001;
		end->y = ((end->x - start->x) * ntan) + start->y;
		step.x = -TSIZE_3D;
		step.y = step.x * ntan;
	}
	if (ray_angle < (PI / 2) || ray_angle > (PI / 2 * 3))
	{
		end->x = (int)(start->x / TSIZE_3D) * TSIZE_3D + TSIZE_3D;
		end->y = ((end->x - start->x) * ntan) + start->y;
		step.x = TSIZE_3D;
		step.y = step.x * ntan;
	}
	ft_loop_v(game, step, end);
}
