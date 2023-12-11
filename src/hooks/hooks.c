/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:27:35 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/11 20:10:56 by jariza-o         ###   ########.fr       */
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

void	w_key(t_game *game)
{
	printf("W\n");
	if (!ft_check_minimap_colision(game, game->player->minimap.y - 1, game->player->minimap.x))
		return ;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	game->player->minimap.y -= 1;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFF0000FF);
}

void	s_key(t_game *game)
{
	printf("S\n");
	if (!ft_check_minimap_colision(game, game->player->minimap.y + 1, game->player->minimap.x))
		return ;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	game->player->minimap.y += 1;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFF0000FF);
}

void	a_key(t_game *game)
{
	printf("A\n");
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFFFFFFFF);
	game->player->minimap.x -= 1;
	ft_paint(game, game->player->minimap.y, game->player->minimap.x, 0xFF0000FF);
}
void	d_key(t_game *game)
{
	printf("D\n");
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
		w_key(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		s_key(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		a_key(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		d_key(game);
	else if (keydata.key == MLX_KEY_LEFT)
		printf("LEFT\n");
		//left_key(game);
	else if (keydata.key == MLX_KEY_RIGHT)
		printf("RIGHT\n");
		//right_key(game);
	// mlx_key_hook(game->mlx, &move_hooks, (void *)(game));
	// mlx_resize_hook(game->mlx, &hook_screen, (void *)(game));
}
