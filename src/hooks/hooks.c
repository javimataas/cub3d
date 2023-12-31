/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:27:35 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/14 17:32:31 by jmatas-p         ###   ########.fr       */
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
	int		move_speed;
	t_coord	new_coord;
	
	move_speed = MV_SPEED;
	if (key == MLX_KEY_W)
		move_speed *= -1;
	// if (!ft_check_minimap_colision_x(game, game->player->minimap.y - 1, game->player->minimap.x, 'w'))
	// 	return ;
	// printf("sin: %f\n", sin(ft_radianes(game->player->angrot)));
	// printf("cos: %f\n", cos(ft_radianes(game->player->angrot)));
	new_coord.x = game->player->minimap.x + (move_speed * sin(ft_radianes(game->player->angrot)));
	new_coord.y = game->player->minimap.y + (move_speed * cos(ft_radianes(game->player->angrot)));
	// ft_printf("new_x: %d\n", new_x);
	// ft_printf("new_y: %d\n", new_y);
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	ft_paint(game, new_coord.y, new_coord.x, 0xFF0000FF);
	game->player->minimap.y = new_coord.y;
	game->player->minimap.x = new_coord.x;
}

void	ad_key(t_game *game, int key)
{

	int		move_speed;
	t_coord	new_coord;
	
	move_speed = MV_SPEED;
	if (key == MLX_KEY_A)
		move_speed *= -1;
	new_coord.x = game->player->minimap.x + (move_speed * sin(ft_radianes(game->player->angrot) + M_PI / 2));
	new_coord.y = game->player->minimap.y + (move_speed * cos(ft_radianes(game->player->angrot)+ M_PI / 2));
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	ft_paint(game, new_coord.y, new_coord.x, 0xFF0000FF);
	game->player->minimap.y = new_coord.y;
	game->player->minimap.x = new_coord.x;

	// int		despl;
	// t_coord	new_coord;
	
	// despl = M_PI / 2;
	// if (key == MLX_KEY_A)
	// 	despl *= -1;
	// ft_printf("x: %d\n", game->player->minimap.x);
	// ft_printf("y: %d\n", game->player->minimap.y);
	// new_coord.x = game->player->minimap.x + (MV_SPEED * sin(ft_radianes(game->player->angrot) + despl));
	// new_coord.y = game->player->minimap.y - (MV_SPEED * cos(ft_radianes(game->player->angrot) + despl));
	// printf("sin: %f\n", sin(ft_radianes(game->player->angrot)));
	// printf("cos: %f\n", cos(ft_radianes(game->player->angrot)));
	// ft_printf("new_x: %d\n", new_coord.x);
	// ft_printf("new_y: %d\n", new_coord.y);
	// // new_coord.x = game->player->minimap.x + cos(ft_radianes(game->player->angrot) + (M_PI / 2)) * MV_SPEED * 0.5;
	// // new_coord.y = game->player->minimap.x - sin(ft_radianes(game->player->angrot) + (M_PI / 2)) * MV_SPEED * 0.5;
	// ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	// ft_paint(game, new_coord.y, new_coord.x, 0xFF0000FF);
	// game->player->minimap.y = new_coord.y;
	// game->player->minimap.x = new_coord.x;
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
