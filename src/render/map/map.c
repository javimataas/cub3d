/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:14:05 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/13 16:31:28 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_background_map(t_game *game)
{
	int		x;
	int		y;
	int 	f;
	int		c;
	t_textures	*aux;

	aux = game->map->texts;
	while (aux)
	{
		if (!ft_strcmp(aux->id, "F"))
			f = aux->color;
		if (!ft_strcmp(aux->id, "C"))
			c = aux->color;
		aux = aux->next;
	}
	y = 0;
	while (y < 540)
	{
		x = 0;
		if (y < 250)
			x = 251;
		while (x < 1920)
		{
			mlx_put_pixel(game->map->img, x, y, c);
			x++;
		}
		y++;
	}
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			mlx_put_pixel(game->map->img, x, y, f);
			x++;
		}
		y++;
	}
}

void	ft_init_colormap(t_game *game)
{
	ft_pixel(game);
	game->map->img = mlx_new_image(game->mlx, 1920, 1080);
	if (!game->map->img)
		ft_error(game, ERR_MLX_FAIL);
	if (mlx_image_to_window(game->mlx, game->map->img, 0, 0) < 0)
		ft_error(game, ERR_MLX_FAIL);
	ft_background_map(game);
	game->map->img->instances[0].z = 1;
}

