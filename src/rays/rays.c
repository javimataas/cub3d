/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:42:44 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/20 17:51:29 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_vert_or_horz(t_game *game, int i)
{
	t_coord	end_v;
	t_coord	end_h;
	double	vlen;
	double	hlen;
	t_coord	coord;

	coord = game->map->player_pos;
	ft_check_horz(game, &coord, &end_h, i);
	ft_check_vert(game, &coord, &end_v, i);
	vlen = sqrt(((end_v.y - coord.y) * (end_v.y - coord.y))
			+ ((end_v.x - coord.x) * (end_v.x - coord.x)));
	hlen = sqrt(((end_h.y - coord.y) * (end_h.y - coord.y))
			+ ((end_h.x - coord.x) * (end_h.x - coord.x)));
	if (hlen <= vlen)
		ft_draw_line(game, game->map->minimap,
			ft_red_coord(coord), ft_red_coord(end_h));
	else
		ft_draw_line(game, game->map->minimap,
			ft_red_coord(coord), ft_red_coord(end_v));
}

void	ft_fix_fish_eye(t_game *game, int i)
{
	float	dist;

	dist = game->player->angrot - game->rays[i].ang;
	if (dist < 0)
		dist += 2 * M_PI;
	if (dist > 2 * M_PI)
		dist -= 2 * M_PI;
	game->rays[i].dist *= cos(dist);
}

void	ft_loop_rays(t_game *game, float angle, int *i)
{
	if (*i != 0)
		game->rays[*i].ang = game->rays[*i - 1].ang + angle;
	if (game->rays[*i].ang >= 2 * M_PI)
		game->rays[*i].ang -= 2 * M_PI;
	else if (game->rays[*i].ang < 0)
		game->rays[*i].ang += 2 * M_PI;
	ft_vert_or_horz(game, *i);
	ft_fix_fish_eye(game, *i);
	(*i)++;
}

void	ft_paint_rays(t_game *game)
{
	int		i;
	float	angle;

	i = 0;
	angle = 0.0174 / 8;
	game->rays[i].ang = game->player->angrot - (240 * angle);
	while (i < 60 * 8)
		ft_loop_rays(game, angle, &i);
}
