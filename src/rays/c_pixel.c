/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pixel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:27:40 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/17 18:14:08 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned long	ft_get_pix_color(mlx_texture_t *text, int x_tex, int y_tex)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	pixel;

	pixel = 4 * x_tex + (y_tex * text->width * 4);
	r = text->pixels[pixel];
	g = text->pixels[pixel + 1];
	b = text->pixels[pixel + 2];
	a = text->pixels[pixel + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_fish_eye(t_game *game, int i)
{
	float	step;

	step = game->player->angrot - game->rays[i].ang;
	if (step < 0)
		step += 2 * PI;
	if (step > 2 * PI)
		step -= 2 * PI;
	game->rays[i].dist *= cos(step);
}
