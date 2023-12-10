/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:12:30 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/10 15:27:56 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"



void	move_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)game;
	printf("JNJKNJK");
	if (keydata.key == MLX_KEY_W)
		printf("W\n");
	else if (keydata.key == MLX_KEY_S)
		printf("S\n");
	else if (keydata.key == MLX_KEY_A)
		printf("A\n");
	else if (keydata.key == MLX_KEY_D)
		printf("D\n");
}
