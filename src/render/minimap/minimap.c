/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:53:48 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/04 18:46:13 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_init_minimap(t_game *game)
{
	// game->canvas = mlx_new_image(game->mlx, 1920, 1080);
	// printf("AGUACATE\n");
	// if (!game->canvas)
	// 	ft_error(game, ERR_MLX_FAIL);
	// if (mlx_image_to_window(game->mlx, game->canvas, 0, 0) < 0)
	// 	ft_error(game, ERR_MLX_FAIL);
	// mlx_put_pixel(game->canvas, 0, 0, 0xFFFFFFFF);
	// mlx_put_pixel(game->canvas, 0, 1, 0xFFFFFFFF);
	// mlx_put_pixel(game->canvas, 0, 2, 0xFFFFFFFF);
	// mlx_put_pixel(game->canvas, 0, 3, 0xFFFFFFFF);
	//game->map->minimap->img = game->canvas;
	//ft_paint_minimap(game);
}

void	ft_paint_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < 331)
	{
		x = 0;
		while (x < 331)
		{
			mlx_put_pixel(game->map->minimap->img, x, y, 0xFFFFFFFF);
		}
	}
}
