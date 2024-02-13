/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:14:05 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/13 22:43:10 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_search_colors(t_textures *textures, int *f_color, int *c_color)
{
	t_textures	*aux;

	aux = textures;
	while (aux)
	{
		if (!ft_strcmp(aux->id, "F"))
			*f_color = aux->color;
		if (!ft_strcmp(aux->id, "C"))
			*c_color = aux->color;
		aux = aux->next;
	}
}

void	ft_draw_up_bg(t_game *game, int c_color)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < 540)
	{
		x = -1;
		while (++x < game->final_s_width)
			mlx_put_pixel(game->map->img, x, y, c_color);
	}
}

void	ft_draw_low_bg(t_game *game, int f_color)
{
	int	x;
	int	y;

	x = -1;
	y = 539;
	while (++y < S_HEIGHT)
	{
		x = -1;
		while (++x < game->final_s_width)
			mlx_put_pixel(game->map->img, x, y, f_color);
	}
}

void	ft_bg_map(t_game *game)
{
	int	f_color;
	int	c_color;

	f_color = 0;
	c_color = 0;
	ft_search_colors(game->map->texts, &f_color, &c_color);
	ft_draw_up_bg(game, c_color);
	ft_draw_low_bg(game, f_color);
	game->map->img->instances[0].z = 0;
}

void	ft_init_colormap(t_game *game)
{
	ft_pixel(game);
	game->map->img = mlx_new_image(game->mlx, game->final_s_width, S_HEIGHT);
	if (!game->map->img)
		ft_error(game, ERR_MLX_FAIL);
	if (mlx_image_to_window(game->mlx, game->map->img, 0, 0) < 0)
		ft_error(game, ERR_MLX_FAIL);
	game->map->img->instances[0].z = -1;
	ft_bg_map(game);
}
