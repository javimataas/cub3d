/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:46:46 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/05 17:52:14 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_paint_animation(t_game *game)
{
	mlx_texture_t	*img_text;
	mlx_texture_t	*img_moved_text;

	img_text = mlx_load_png("animations/sin_mover.png");
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
