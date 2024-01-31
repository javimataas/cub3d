/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:12:30 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/30 22:53:11 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	// ft_paint(game, game->player->minimap.y,
	//	game->player->minimap.x, 0xFFFFFFFF);
	// ft_paint(game, futur_pos.y, futur_pos.x, 0xFF0000FF);
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
	//ft_paint(game, game->player->minimap.y,
	//	game->player->minimap.x, 0xFFFFFFFF);
	//ft_paint(game, futur_pos.y, futur_pos.x, 0xFF0000FF);
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
	// ft_paint(game, game->player->minimap.y,
	// 	game->player->minimap.x, 0xFFFFFFFF);
	// ft_paint(game, futur_pos.y, futur_pos.x, 0xFF0000FF);
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
}
