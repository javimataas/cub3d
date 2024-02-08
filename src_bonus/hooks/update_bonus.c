/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:56:27 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/08 22:11:15 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	ft_update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	check_movement(game);
	ft_rays(game);
	ft_display_pov(game);
	ft_animate(game);
}
