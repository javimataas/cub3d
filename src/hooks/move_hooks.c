/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:12:30 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/01 16:42:39 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_repos_minimap(t_game *game, int letter)
{
	int	y;
	int	x;
	int	counter;
	int	moved;

	y = (int)game->player->minimap.y;
	x = (int)game->player->minimap.x;
	counter = 0;
	moved = 0;
	if (letter == 1)
	{
		while (y >= 0 && game->map->map[y / 10][x / 10] && counter < 120)
		{
			y--;
			counter++;
		}
		if (counter == 120)
		{
			while (y >= 0 && game->map->map[y / 10][x / 10])
			{
				y--;
				moved++;
			}
			moved *= -1;
		}
		else
		{
			while (counter < 120)
			{
				moved++;
				counter++;
			}
		}
	}
	else
	{
		while (x >= 0 && game->map->map[y / 10][x / 10] && counter < 120)
		{
			x--;
			counter++;
		}
		if (counter == 120)
		{
			while (x >= 0 && game->map->map[y / 10][x / 10])
			{
				x--;
				moved++;
			}
			moved *= -1;
		}
		else
		{
			while (counter < 120)
			{
				moved++;
				counter++;
			}
		}
	}
	return (moved);
}

void	ft_repaint_minimap(t_game *game, int img)
{
	if (img)
		mlx_delete_image(game->mlx, game->minimap->img);
	game->minimap->img = mlx_new_image(game->mlx, ft_calc_size(game, 1), ft_calc_size(game, 0)); // CALCULAR TAMAÑO QUE VA A TENER EL MAPA
	if (mlx_image_to_window(game->mlx, game->minimap->img, ft_repos_minimap(game, 0), ft_repos_minimap(game, 1)) < 0) // CALCULAR DONDE EMPIEZA EL MAPA
		ft_error(game, ERR_MLX_FAIL);
	ft_paint_elements(game);
	game->minimap->img->instances[0].z = 1;
}

void	w_key(t_game *game)
{
	t_coord	futur_pos;

	futur_pos.x = game->player->minimap.x
		+ cos(game->player->angrot) * MV_SPEED * 10;
	futur_pos.y = game->player->minimap.y
		- (sin(game->player->angrot) * MV_SPEED * 10);
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game))
		game->player->minimap.x += cos(game->player->angrot) * MV_SPEED;
	if (ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		game->player->minimap.y -= sin(game->player->angrot) * MV_SPEED;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game) && ft_check_wall(game->player->minimap.x, futur_pos.y, game))
	{
		printf("ESQUINA Y: %f X: %f\n", game->player->minimap.y, game->player->minimap.x);
		ft_repaint_minimap(game, 1);
	}
}

void	s_key(t_game *game)
{
	t_coord	futur_pos;

	futur_pos.x = game->player->minimap.x
		- cos(game->player->angrot) * MV_SPEED * 10;
	futur_pos.y = game->player->minimap.y
		+ (sin(game->player->angrot) * MV_SPEED * 10);
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game))
		game->player->minimap.x -= cos(game->player->angrot) * MV_SPEED;
	if (ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		game->player->minimap.y += sin(game->player->angrot) * MV_SPEED;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game) && ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		ft_repaint_minimap(game, 1);
}

void	a_key(t_game *game)
{
	t_coord	futur_pos;

	futur_pos.x = game->player->minimap.x
		+ cos(game->player->angrot + (PI / 2)) * MV_SPEED * 5;
	futur_pos.y = game->player->minimap.y
		- sin(game->player->angrot + (PI / 2)) * MV_SPEED * 5;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game))
		game->player->minimap.x += cos(game->player->angrot + (PI / 2))
			* MV_SPEED;
	if (ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		game->player->minimap.y -= sin(game->player->angrot + (PI / 2))
			* MV_SPEED;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game) && ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		ft_repaint_minimap(game, 1);
}

void	d_key(t_game *game)
{
	t_coord	futur_pos;

	futur_pos.x = game->player->minimap.x
		+ cos(game->player->angrot - (PI / 2)) * MV_SPEED * 5;
	futur_pos.y = game->player->minimap.y
		- sin(game->player->angrot - (PI / 2)) * MV_SPEED * 5;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game))
		game->player->minimap.x += cos(game->player->angrot - (PI / 2)) * MV_SPEED;
	if (ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		game->player->minimap.y -= sin(game->player->angrot - (PI / 2)) * MV_SPEED;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game) && ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		ft_repaint_minimap(game, 1);
}
