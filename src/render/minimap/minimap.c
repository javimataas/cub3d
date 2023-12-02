/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:53:48 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/02 17:03:15 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_init_minimap(t_game *game)
{
	game->map->minimap->img = mlx_new_image(game->mlx, 331, 331);
	printf("AGUACATE\n");
	if (!game->map->minimap->img)
		ft_error(game, ERR_MLX_FAIL);
	if (mlx_image_to_window(game->mlx, game->map->minimap->img, 40, 40))
		ft_error(game, ERR_MLX_FAIL);
	ft_paint_minimap(game);
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
