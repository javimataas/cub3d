/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:34:01 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/10 15:22:31 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	view_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)game;
	// CAMBIAR COMPARACION EN LOS IF
	if (keydata.key == MLX_KEY_LEFT)
		printf("LEFT\n");
		//left_key(game);
	else if (keydata.key == MLX_KEY_RIGHT)
		printf("RIGHT\n");
		//right_key(game);
}