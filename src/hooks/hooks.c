/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:27:35 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/05 17:59:45 by jmatas-p         ###   ########.fr       */
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

void	press_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W)
		game->player->moving |= 0x01;
	if (keydata.key == MLX_KEY_S)
		game->player->moving |= 0x04;
	if (keydata.key == MLX_KEY_A)
		game->player->moving |= 0x02;
	if (keydata.key == MLX_KEY_D)
		game->player->moving |= 0x08;
	if (keydata.key == MLX_KEY_RIGHT)
		game->player->moving |= 0x10;
	if (keydata.key == MLX_KEY_LEFT)
		game->player->moving |= 0x20;
	if (keydata.key == MLX_KEY_SPACE)
		game->player->moving |= 0x40;
}

void	release_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W)
		game->player->moving &= ~0x01;
	if (keydata.key == MLX_KEY_S)
		game->player->moving &= ~0x04;
	if (keydata.key == MLX_KEY_A)
		game->player->moving &= ~0x02;
	if (keydata.key == MLX_KEY_D)
		game->player->moving &= ~0x08;
	if (keydata.key == MLX_KEY_RIGHT)
		game->player->moving &= ~0x10;
	if (keydata.key == MLX_KEY_LEFT)
		game->player->moving &= ~0x20;
	if (keydata.key == MLX_KEY_SPACE)
		game->player->moving &= ~0x40;
}

void	ft_move_player(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		escape_hook(game);
	if (keydata.action == MLX_PRESS)
		press_key(keydata, param);
	if (keydata.action == MLX_RELEASE)
		release_key(keydata, param);
}

void	ft_update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	check_movement(game);
	ft_rays(game);
	ft_display_pov(game);
}
