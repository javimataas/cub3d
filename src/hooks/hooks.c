/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:27:35 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/13 19:30:28 by jmatas-p         ###   ########.fr       */
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
	int	move_speed;
	int	new_x;
	int new_y;
	
	move_speed = MV_SPEED;
	if (key == MLX_KEY_W)
		move_speed *= -1;
	// if (!ft_check_minimap_colision_x(game, game->player->minimap.y - 1, game->player->minimap.x, 'w'))
	// 	return ;
	printf("sin: %f\n", sin(game->player->angulorotacion * PI / 180));
	printf("cos: %f\n", cos(game->player->angulorotacion * PI / 180));
	new_x = game->player->minimap.x + (move_speed * sin(game->player->angulorotacion * PI / 180));
	new_y = game->player->minimap.y + (move_speed * cos(game->player->angulorotacion * PI / 180));
	ft_printf("new_x: %d\n", new_x);
	ft_printf("new_y: %d\n", new_y);
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	ft_paint(game, new_y, new_x, 0xFF0000FF);
	game->player->minimap.y = new_y; 
	game->player->minimap.x = new_x;
}

void	s_key(t_game *game)
{
	printf("S\n");
	if (!ft_check_minimap_colision_x(game, game->player->minimap.y + 1, game->player->minimap.x, 's'))
		return ;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	game->player->minimap.y += 1;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFF0000FF);
}

void	a_key(t_game *game)
{
	printf("A\n");
	// if (!ft_check_minimap_colision_y(game, game->player->minimap.y, game->player->minimap.x - 1))
	// 	return ;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	game->player->minimap.x -= 1;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFF0000FF);
}
void	d_key(t_game *game)
{
	printf("D\n");
	// if (!ft_check_minimap_colision_y(game, game->player->minimap.y, game->player->minimap.x + 1))
	// 	return ;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	game->player->minimap.x += 1;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFF0000FF);
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
		a_key(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		d_key(game);
	else if (keydata.key == MLX_KEY_LEFT)
	{
		printf("LEFT\n");
		if (game->player->angulorotacion == 359)
			game->player->angulorotacion = 0;
		else
			game->player->angulorotacion += 1;
		printf("angulo: %f\n", game->player->angulorotacion);
		//left_key(game);
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		printf("RIGHT\n");
		if (game->player->angulorotacion == 0)
			game->player->angulorotacion = 359;
		else
			game->player->angulorotacion -= 1;
		printf("angulo: %f\n", game->player->angulorotacion);
		//right_key(game);
	}
	// mlx_key_hook(game->mlx, &move_hooks, (void *)(game));
	// mlx_resize_hook(game->mlx, &hook_screen, (void *)(game));
}
