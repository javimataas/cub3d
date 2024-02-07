/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:46:46 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/07 16:02:56 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_paint_animation(t_game *game)
{
	mlx_texture_t	*img_text;
	mlx_texture_t	*img_moved_text;

	img_text = mlx_load_png("animations/sin_mover_o.png");
	img_moved_text = mlx_load_png("animations/movida.png");
	game->animation->img = mlx_texture_to_image(game->mlx, img_text);
	game->animation->img_moved = mlx_texture_to_image(game->mlx, img_moved_text);
	mlx_delete_texture(img_text);
	mlx_delete_texture(img_moved_text);
	// game->animation->img = mlx_new_image(game->mlx, 400, 400);
	// game->animation->img_moved = mlx_new_image(game->mlx, 400, 400);
	if (mlx_image_to_window(game->mlx, game->animation->img, 1300, 800) < 0)
		ft_error(game, ERR_MLX_FAIL);
	if (mlx_image_to_window(game->mlx, game->animation->img_moved, 1300, 800) < 0)
		ft_error(game, ERR_MLX_FAIL);
	game->animation->img_moved->instances[0].enabled = false;
	game->animation->img->instances[0].enabled = true;
}

void	ft_animate(t_game *game)
{
	float animation_switch_time;

	animation_switch_time = 0.5f;
	printf("delta_time: %f\n", game->mlx->delta_time);
	game->animation->img_moved->instances[0].enabled = true;
	game->animation->img->instances[0].enabled = false;
	game->animation->time += game->mlx->delta_time;
	if (game->animation->time >= animation_switch_time)
	{
		printf("ACUMULATOR %f\n", game->animation->time);
		game->animation->img->instances[0].enabled = true;
		game->animation->img_moved->instances[0].enabled = false;

		game->animation->time = 0.0f;
	}
}


// void	ft_paint_animation(t_game *game)
// {
// 	mlx_texture_t	*img_text[5];
// 	int				i;

// 	img_text[0] = mlx_load_png("animations/sin_mover.png");
// 	img_text[1] = mlx_load_png("animations/mov_1.png");
// 	img_text[2] = mlx_load_png("animations/mov_2.png");
// 	img_text[3] = mlx_load_png("animations/mov_3.png");
// 	img_text[4] = mlx_load_png("animations/mov_4.png");
// 	i = -1;
// 	while (++i < 5)
// 		game->animation->img[i] = mlx_texture_to_image(game->mlx, img_text[i]);
// 	i = -1;
// 	while (++i < 5)
// 		mlx_delete_texture(img_text[i]);
// 	// game->animation->img = mlx_new_image(game->mlx, 400, 400);
// 	// game->animation->img_moved = mlx_new_image(game->mlx, 400, 400);
// 	i = -1;
// 	while (++i < 5)
// 		if (mlx_image_to_window(game->mlx, game->animation->img[i], 1300, 800) < 0)
// 			ft_error(game, ERR_MLX_FAIL);
// 	i = 0;
// 	game->animation->img[i]->instances[0].enabled = true;
// 	while (++i < 5)
// 		game->animation->img[i]->instances[0].enabled = false;
// }

// void	ft_animate(t_game *game)
// {
// 	float animation_switch_time;

// 	animation_switch_time = 0.5f;
// 	printf("delta_time: %f\n", game->mlx->delta_time);
// 	game->animation->img[1]->instances[0].enabled = true;
// 	game->animation->img[0]->instances[0].enabled = false;
// 	game->animation->time += game->mlx->delta_time;
// 	if (game->animation->time >= animation_switch_time)
// 	{
// 		printf("ACUMULATOR %f\n", game->animation->time);
// 		game->animation->img[2]->instances[0].enabled = true;
// 		game->animation->img[1]->instances[0].enabled = false;
// 	}
// 	game->animation->time += 0.5f;
// 	if (game->animation->time >= animation_switch_time)
// 	{
// 		game->animation->img[3]->instances[0].enabled = true;
// 		game->animation->img[2]->instances[0].enabled = false;
// 	}
// 	game->animation->time += 0.5f;
// 	if (game->animation->time >= animation_switch_time)
// 	{
// 		game->animation->img[4]->instances[0].enabled = true;
// 		game->animation->img[3]->instances[0].enabled = false;
// 	}
// 	game->animation->time += 0.5f;
// 	if (game->animation->time >= animation_switch_time)
// 	{
// 		game->animation->img[0]->instances[0].enabled = true;
// 		game->animation->img[4]->instances[0].enabled = false;
// 	}
// 	game->animation->time = 0.0f;
// }
