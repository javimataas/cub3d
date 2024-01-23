/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:48:30 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/23 17:14:42 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_struct_hray(t_game *game, int i, t_coord hor, double h_len)
{
	game->rays[i].dist = h_len;
	game->rays[i].color = game->c_pix;
	game->rays[i].hit.x = hor.x;
	game->rays[i].hit.y = hor.y;
	game->rays[i].dir = 'N';
	if (game->rays[i].ang > PI)
	{
		game->rays[i].color = 0x0000ffff;
		game->rays[i].dir = 'S';
	}
}

void	ft_struct_vray(t_game *game, int i, t_coord vert, double v_len)
{
	game->rays[i].dist = v_len;
	game->rays[i].color = 0x00ff00ff;
	game->rays[i].hit.x = vert.x;
	game->rays[i].hit.y = vert.y;
	game->rays[i].dir = 'E';
	if (game->rays[i].ang > PI / 2 && game->rays[i].ang < PI / 2 * 3)
	{
		game->rays[i].color = 0xff00ffff;
		game->rays[i].dir = 'W';
	}
}

void	ft_vert_hor(t_game *game, int i)
{
	t_coord	vert;
	t_coord	hor;
	double	v_len;
	double	h_len;
	t_coord	point;

	point = game->player->minimap;
	ft_check_h(game, &point, &hor, i);
	ft_check_v(game, &point, &vert, i);
	v_len = sqrt(pow(vert.x - point.x, 2) + pow(vert.y - point.y, 2));
	h_len = sqrt(pow(hor.x - point.x, 2) + pow(hor.y - point.y, 2));
	if (h_len <= v_len)
		ft_struct_hray(game, i, hor, h_len);
	else
		ft_struct_vray(game, i, vert, v_len);
}

void	ft_loop_rays(t_game *game, float ray_angle, int *i)
{
	if (*i != 0)
		game->rays[*i].ang = game->rays[*i - 1].ang + ray_angle;
	if (game->rays[*i].ang >= 2 * PI)
		game->rays[*i].ang -= 2 * PI;
	else if (game->rays[*i].ang < 0)
		game->rays[*i].ang += (2 * PI);
	ft_vert_hor(game, *i);
	ft_fish_eye(game, *i);
	(*i)++;
}

void	ft_rays(t_game *game)
{
	int		i;
	float	ray_angle;

	i = 0;
	ray_angle = 0.0174 / DEF;
	game->rays[i].ang = game->player->angrot - (game->pov_ang / 2 * ray_angle);
	while (i < game->pov_ang)
		ft_loop_rays(game, ray_angle, &i);
}
