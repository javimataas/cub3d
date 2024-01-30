/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:27:35 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/23 18:40:17 by jariza-o         ###   ########.fr       */
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
	mlx_delete_image(game->mlx, game->map->img); //PORQUE ELIMINA LAS IMAGENES // HAY QUE ELIMINARLAS TODAS??
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
			mlx_put_pixel(game->minimap->img, x + n, y + i, color);
	}
}

// int	ft_colision(t_game *game, t_player *new_coord)
// {
// 	int	y;
// 	int	x;
// 	y = new_coord->minimap.y / 10;
// 	x = new_coord->minimap.x / 10;
// 	printf("MAPA: %c Y: %d X: %d\n", game->map->map[y][x], y, x);
// 	//comprueba que se mueve en horizontal o vertical
// 	if ((new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x == game->player->minimap.x) && (game->player->angrot == 0 || game->player->angrot == 180 || game->player->angrot == 270 || game->player->angrot == 90))
// 		y--;
// 	else if ((new_coord->minimap.y == game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x) && (game->player->angrot == 0 || game->player->angrot == 180 || game->player->angrot == 270 || game->player->angrot == 90))
// 		x--;
// 	else if ((new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x) || (new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x > game->player->minimap.x))
// 		y--;
// 	else if (new_coord->minimap.y > game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x)
// 		x--;
	
// 	// else if (new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x)
// 	// 	x = (new_coord->minimap.x + 14) / 14;
	
// 	if (game->map->map[y][x] == '1')
// 	{
// 		printf("CHOCAAA MAPA: %c Y: %d X: %d\n", game->map->map[y][x], y, x);
// 		return (0);
// 	}
// 	// NUEVO
// 	// game->player->player_pos.y = y;
// 	// game->player->player_pos.x = x;
// 	return (1);
// }

// void	ws_key(t_game *game, int key)
// {

// }

// void	ad_key(t_game *game, int key)
// {

// }

void	ft_init_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		escape_hook(game);
	// else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	// 	ws_key(game, MLX_KEY_W);
	// else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	// 	ws_key(game, MLX_KEY_S);
	// else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	// 	ad_key(game, MLX_KEY_A);
	// else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	// 	ad_key(game, MLX_KEY_D);
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
