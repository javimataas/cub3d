/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:26:52 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/20 17:47:04 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_loop_horz(t_game *game, t_coord step, t_coord *end)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	while (k < game->map->height)
	{
		if (end->y >= 0 && end->y < (TILESIZE_3D * game->map->height)
			&& end->x >= 0 && end->x < (TILESIZE_3D * game->map->width))
		{
			i = end->y / TILESIZE_3D;
			j = end->x / TILESIZE_3D;
			if (i < 0 || j < 0 || i >= game->map->height
				|| j >= game->map->width || game->map->map[i][j] == '1')
				break ;
			else
				ft_inc_step(step, end, &k);
		}
		else
			break ;
	}
}

void	ft_check_horz(t_game *game, t_coord *start, t_coord *end, int i)
{
	t_coord	step;
	float	ra;
	float	atan;

	ra = game->rays[i].ang;
	atan = -1 / tan(ra);
	if (ra > M_PI)
	{
		end->y = (int)(start->y / TILESIZE_3D) * TILESIZE_3D + TILESIZE_3D;
		end->x = (end->y - start->y) * atan + start->x;
		step.y = TILESIZE_3D;
		step.x = step.y * atan;
	}
	if (ra < M_PI)
	{
		end->y = ((int)start->y / TILESIZE_3D) * TILESIZE_3D - 0.0001;
		end->x = (end->y - start->y) * atan + start->x;
		step.y = -TILESIZE_3D;
		step.x = step.y * atan;
	}
	ft_loop_horz(game, step, end);
}

void	ft_loop_vert(t_game *game, t_coord step, t_coord *end)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	while (k < game->map->width)
	{
		if (end->y >= 0 && end->y < (TILESIZE_3D * game->map->height)
			&& end->x >= 0 && end->x < (TILESIZE_3D * game->map->width))
		{
			i = end->y / TILESIZE_3D;
			j = end->x / TILESIZE_3D;
			if (i < 0 || j < 0 || i > game->map->height
				|| j > game->map->width || game->map->map[i][j] == '1')
				break ;
			else
				ft_inc_step(step, end, &k);
		}
		else
			break ;
	}
}

void	ft_check_vert(t_game *game, t_coord *start, t_coord *end, int i)
{
	t_coord	step;
	float	ra;
	float	ntan;

	ra = game->rays[i].ang;
	ntan = -tan(ra);
	if (ra > (M_PI / 2) && ra < (M_PI / 2 * 3))
	{
		end->x = ((int)start->x / TILESIZE_3D) * TILESIZE_3D - 0.001;
		end->y = (end->x - start->x) * ntan + start->y;
		step.x = -TILESIZE_3D;
		step.y = step.x * ntan;
	}
	if (ra < (M_PI / 2) || ra > (M_PI / 2 * 3))
	{
		end->x = ((int)start->x / TILESIZE_3D) * TILESIZE_3D + TILESIZE_3D;
		end->y = (end->x - start->x) *ntan + start->y;
		step.x = TILESIZE_3D;
		step.y = step.x * ntan;
	}
	ft_loop_vert(game, step, end);
}
