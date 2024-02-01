/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:27:35 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/01 16:12:34 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	escape_hook(t_game *game)
{
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	ft_clear(game);
	exit(1);
}

void	hook_screen(int32_t width, int32_t height, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (width < 1800 || height < 1100)
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_delete_image(game->mlx, game->map->img);
	game->map->img = mlx_new_image(game->mlx, width, height);
	if (mlx_image_to_window(game->mlx, game->map->img, 30, 30) < 0)
		exit (1);
}

void	ft_init_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		escape_hook(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		w_key(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		s_key(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		a_key(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		d_key(game);
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		printf("LEFT\n");
		game->player->angrot -= 0.04;
		if (game->player->angrot < 0)
			game->player->angrot += 2 * PI;
		printf("angulo: %f\n", game->player->angrot);
		//left_key(game);
	}
	else if (keydata.key == MLX_KEY_LEFT)
	{
		printf("RIGHT\n");
		game->player->angrot += 0.04;
		if (game->player->angrot >= 2 * PI)
			game->player->angrot -= 2 * PI;
		printf("angulo: %f\n", game->player->angrot);
		//right_key(game);
	}
	// mlx_key_hook(game->mlx, &move_hooks, (void *)(game));
	// mlx_resize_hook(game->mlx, &hook_screen, (void *)(game));
}

void	ft_update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_rays(game);
	ft_display_pov(game);
}
