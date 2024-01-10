/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:48:30 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/10 19:38:51 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_rays(t_game *game)
{
    int		i;
    double	ray_angle;

    i = 0;
    ray_angle = 0.0174 / DEF;
	game->rays[i].ang = game->player->angrot - (game->pov_ang / 2 * ray_angle);
}