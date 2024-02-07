/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:06:32 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/07 19:41:42 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
