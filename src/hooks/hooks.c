/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:27:35 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/11 16:36:11 by jariza-o         ###   ########.fr       */
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

void	ft_paint(t_game *game, int y, int x, int color)
{
	int	i;
	int	n;
	
	i = -1;
	while ((y + (++i)) < (y + 14))
	{
		n = -1;
		while ((x + (++n)) < (x + 14))
			mlx_put_pixel(game->map->minimap, x + n, y + i, color);
	}
}

void	ws_key(t_game *game, int key)
{
	int			move_speed;
	t_player	*new_coord;

	move_speed = MV_SPEED;
	if (key == MLX_KEY_W)
		move_speed *= -1;
	new_coord = malloc(sizeof(t_player));
	new_coord->minimap.x = game->player->minimap.x + (move_speed * sin(ft_radianes(game->player->angrot)));
	new_coord->minimap.y = game->player->minimap.y + (move_speed * cos(ft_radianes(game->player->angrot)));
	printf("X: %f Y: %f\n", new_coord->minimap.x, new_coord->minimap.y);
	// if (!ft_front_colision(game, new_coord) || !ft_back_colision(game, new_coord))
	// 	return ;
	// if (!ft_colision(game, new_coord))
	// 	return ;
	// if ((new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x == game->player->minimap.x))
		// if (!ft_back_colision(game, new_coord)) // || !ft_back_colision(game, new_coord))
		// 	return ;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	ft_paint(game, new_coord->minimap.y, new_coord->minimap.x, 0xFF0000FF);
	game->player->minimap.y = new_coord->minimap.y;
	game->player->minimap.x = new_coord->minimap.x;
	ft_calc_coords(game->player);
}

void	ad_key(t_game *game, int key)
{

	int			move_speed;
	t_player	*new_coord;
	
	move_speed = MV_SPEED;
	if (key == MLX_KEY_A)
		move_speed *= -1;
	new_coord = malloc(sizeof(t_player));
	new_coord->minimap.x = game->player->minimap.x + (move_speed * sin(ft_radianes(game->player->angrot) + M_PI / 2));
	new_coord->minimap.y = game->player->minimap.y + (move_speed * cos(ft_radianes(game->player->angrot)+ M_PI / 2));
	// if (!ft_right_colision(game, new_coord) || !ft_left_colision(game, new_coord))
	// 	return ;
	// if (!ft_colision(game, new_coord))
	// 	return ;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	ft_paint(game, new_coord->minimap.y, new_coord->minimap.x, 0xFF0000FF);
	game->player->minimap.y = new_coord->minimap.y;
	game->player->minimap.x = new_coord->minimap.x;
	ft_calc_coords(game->player);
}

void	ft_init_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		escape_hook(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		ws_key(game, MLX_KEY_W);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		ws_key(game, MLX_KEY_S);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		ad_key(game, MLX_KEY_A);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		ad_key(game, MLX_KEY_D);
	else if (keydata.key == MLX_KEY_LEFT)
	{
		printf("LEFT\n");
		if (game->player->angrot == 359)
			game->player->angrot = 0;
		else
			game->player->angrot += 1;
		printf("angulo: %f\n", game->player->angrot);
		//left_key(game);
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		printf("RIGHT\n");
		if (game->player->angrot == 0)
			game->player->angrot = 359;
		else
			game->player->angrot -= 1;
		printf("angulo: %f\n", game->player->angrot);
		//right_key(game);
	}
	// mlx_key_hook(game->mlx, &move_hooks, (void *)(game));
	// mlx_resize_hook(game->mlx, &hook_screen, (void *)(game));
}
