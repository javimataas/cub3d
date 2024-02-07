/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:34:01 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/07 16:57:53 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	view_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)game;
	if (keydata.key == MLX_KEY_LEFT)
		printf("LEFT\n");
	else if (keydata.key == MLX_KEY_RIGHT)
		printf("RIGHT\n");
}
