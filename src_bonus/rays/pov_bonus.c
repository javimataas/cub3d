/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:57:11 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/08 22:10:42 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	init_pov_display(t_game *game)
{
	game->start.x = 0;
	game->pix.x = 0;
	if (game->img3d)
		mlx_delete_image(game->mlx, game->img3d);
	game->img3d = mlx_new_image(game->mlx, game->final_s_width, S_HEIGHT);
	if (!game->img3d || (mlx_image_to_window(game->mlx, game->img3d, 0, 0) < 0))
		return ;
	game->img3d->instances[0].z = 1;
}

void	ft_get_pix_x(t_game *g, int i, mlx_texture_t **text)
{
	if (g->rays[i].dir == 'N' || g->rays[i].dir == 'S')
	{
		*text = g->textures[0];
		g->pix.x = (int)(g->rays[i].hit.x) % TSIZE_3D;
		if (g->rays[i].ang > PI)
		{
			*text = g->textures[1];
			g->pix.x = (TSIZE_3D - g->pix.x - 1) * (*text)->width / TSIZE_3D;
		}
		else
			g->pix.x = g->pix.x * (*text)->width / TSIZE_3D;
	}
	else
	{
		*text = g->textures[2];
		g->pix.x = (int)(g->rays[i].hit.y) % TSIZE_3D;
		if (g->rays[i].ang > PI / 2 && g->rays[i].ang < PI / 2 * 3)
		{
			*text = g->textures[3];
			g->pix.x = (TSIZE_3D - g->pix.x - 1) * (*text)->width / TSIZE_3D;
		}
		else
			g->pix.x = g->pix.x * (*text)->width / TSIZE_3D;
	}
}

void	ft_draw_pixel(t_game *game, mlx_texture_t *texture, int start_y)
{
	int		px;

	px = 0;
	while (px < game->h_line)
	{
		if (((game->start.x < game->final_s_width - 1) && game->start.x >= -10)
			&& (start_y + px < (S_HEIGHT - 1) && start_y + px >= 0))
		{
			game->c_pix = ft_get_pix_color(texture, game->pix.x, game->pix.y);
			if (game->start.x > 250 || (start_y + px) > 250)
				mlx_put_pixel(game->img3d, game->start.x,
					start_y + px, game->c_pix);
		}
		px++;
		game->pix.y += game->ty_step;
	}
}

void	ft_draw_pixels(t_game *game, mlx_texture_t *texture)
{
	if (game->h_line < S_HEIGHT)
		ft_draw_pixel(game, texture, game->start.y);
	else
	{
		game->pix.y = -(game->start.y * game->ty_step);
		game->h_line = S_HEIGHT;
		ft_draw_pixel(game, texture, 0);
	}
}

int	ft_display_pov(t_game *game)
{
	int				i;
	int				j;
	mlx_texture_t	*texture;

	i = game->pov_ang - 1;
	init_pov_display(game);
	while (i >= 0)
	{
		j = 0;
		while (j < game->final_s_width / game->pov_ang)
		{
			game->pix.y = 0;
			ft_get_pix_x(game, i, &texture);
			game->h_line = S_HEIGHT / game->rays[i].dist * TSIZE_3D * DEPTH;
			game->ty_step = texture->height / (float)game->h_line;
			game->start.y = (S_HEIGHT - game->h_line) / 2;
			game->end.x = game->start.x;
			game->end.y = game->start.y + game->h_line;
			ft_draw_pixels(game, texture);
			j++;
			game->start.x++;
		}
		i--;
	}
	return (1);
}
