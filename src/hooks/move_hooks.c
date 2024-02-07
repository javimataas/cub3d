/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:12:30 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/07 17:02:45 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	w_key(t_game *game)
{
	t_coord	futur_pos;

	futur_pos.x = game->player->minimap.x + \
	cos(game->player->angrot) * MV_SPEED * 10;
	futur_pos.y = game->player->minimap.y - \
	(sin(game->player->angrot) * MV_SPEED * 10);
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game))
		game->player->minimap.x += cos(game->player->angrot) * MV_SPEED;
	if (ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		game->player->minimap.y -= sin(game->player->angrot) * MV_SPEED;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game) || \
	ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		ft_paint_minimap(game, 1, 1);
}

void	s_key(t_game *game)
{
	t_coord	futur_pos;

	futur_pos.x = game->player->minimap.x - \
	cos(game->player->angrot) * MV_SPEED * 10;
	futur_pos.y = game->player->minimap.y + \
	(sin(game->player->angrot) * MV_SPEED * 10);
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game))
		game->player->minimap.x -= cos(game->player->angrot) * MV_SPEED;
	if (ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		game->player->minimap.y += sin(game->player->angrot) * MV_SPEED;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game) || \
	ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		ft_paint_minimap(game, 1, 1);
}

void	a_key(t_game *game)
{
	t_coord	futur_pos;

	futur_pos.x = game->player->minimap.x + \
	cos(game->player->angrot + (PI / 2)) * MV_SPEED
		* 5;
	futur_pos.y = game->player->minimap.y - \
	sin(game->player->angrot + (PI / 2)) * MV_SPEED
		* 5;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game))
		game->player->minimap.x += cos(game->player->angrot + \
		(PI / 2)) * MV_SPEED;
	if (ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		game->player->minimap.y -= sin(game->player->angrot + \
		(PI / 2)) * MV_SPEED;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game) || \
	ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		ft_paint_minimap(game, 1, 1);
}

void	d_key(t_game *game)
{
	t_coord	futur_pos;

	futur_pos.x = game->player->minimap.x + \
	cos(game->player->angrot - (PI / 2)) * MV_SPEED
		* 5;
	futur_pos.y = game->player->minimap.y - \
	sin(game->player->angrot - (PI / 2)) * MV_SPEED
		* 5;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game))
		game->player->minimap.x += cos(game->player->angrot - \
		(PI / 2)) * MV_SPEED;
	if (ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		game->player->minimap.y -= sin(game->player->angrot - \
		(PI / 2)) * MV_SPEED;
	if (ft_check_wall(futur_pos.x, game->player->minimap.y, game) || \
	ft_check_wall(game->player->minimap.x, futur_pos.y, game))
		ft_paint_minimap(game, 1, 1);
}

void	check_movement(t_game *game)
{
	if (game->player->moving & 0x01)
		w_key(game);
	else if (game->player->moving & 0x04)
		s_key(game);
	if (game->player->moving & 0x02)
		a_key(game);
	else if (game->player->moving & 0x08)
		d_key(game);
	if (game->player->moving & 0x10)
	{
		game->player->angrot -= 0.04;
		if (game->player->angrot < 0)
			game->player->angrot += (2 * PI);
	}
	else if (game->player->moving & 0x20)
	{
		game->player->angrot += 0.04;
		if (game->player->angrot > (2 * PI))
			game->player->angrot -= (2 * PI);
	}
}
