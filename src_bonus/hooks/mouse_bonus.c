/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:06:32 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/08 22:11:09 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)xdelta;
	if (ydelta > 0)
	{
		game->player->angrot -= 0.04;
		if (game->player->angrot < 0)
			game->player->angrot += 2 * PI;
	}
	else if (ydelta < 0)
	{
		game->player->angrot += 0.04;
		if (game->player->angrot >= 2 * PI)
			game->player->angrot -= 2 * PI;
	}
}
