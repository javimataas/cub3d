/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:46:46 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/01 18:16:36 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_paint_animation(t_game *game)
{
	static int		delete;
	mlx_texture_t	*img_text;
	mlx_texture_t	*img_moved_text;
	mlx_image_t		*img;
	mlx_image_t		*img_moved;

	img_text = mlx_load_png("animations/sin_mover.png");
	img_moved_text = mlx_load_png("animations/movida.png");
	img = mlx_texture_to_image(game->mlx, img_text);
	img_moved = mlx_texture_to_image(game->mlx, img_moved_text);
	mlx_delete_texture(img_text);
	mlx_delete_texture(img_moved_text);
	if (delete == 1)
		mlx_delete_image(game->mlx, game->animation->img);
	delete = 1;
	game->animation->img = mlx_new_image(game->mlx, 400, 400);
	game->animation->img_moved = mlx_new_image(game->mlx, 400, 400);
	if (mlx_image_to_window(game->mlx, img, 200, 100) < 0)
		ft_error(game, ERR_MLX_FAIL);
	if (mlx_image_to_window(game->mlx, img_moved, 200, 100) < 0)
		ft_error(game, ERR_MLX_FAIL);
	while (1)
	{
		game->animation->img->instances[0].z = 2;
		game->animation->img->instances[0].z = -2;
		game->animation->img_moved->instances[0].z = 2;
		game->animation->img_moved->instances[0].z = -2;
	}
}
