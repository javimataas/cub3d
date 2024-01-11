/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colission.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:11:26 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/11 16:19:59 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_colision(t_game *game, t_player *new_coord)
{
	int	y;
	int	x;
	y = (int)new_coord->minimap.y / 14;
	x = (int)new_coord->minimap.x / 14;
	printf("MAPA: %c Y: %d X: %d\n", game->map->map[y][x], y, x);
	//comprueba que se mueve en horizontal o vertical
	// game->player->angrot = 45;
	if ((new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x == game->player->minimap.x) && (game->player->angrot == 0 || game->player->angrot == 180 || game->player->angrot == 270 || game->player->angrot == 90))
		y--;
	else if ((new_coord->minimap.y == game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x) && (game->player->angrot == 0 || game->player->angrot == 180 || game->player->angrot == 270 || game->player->angrot == 90))
		x--;
	else if ((new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x) || (new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x > game->player->minimap.x))
		y--;
	else if (new_coord->minimap.y > game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x)
		x--;
	
	// else if (new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x)
	// 	x = (new_coord->minimap.x + 14) / 14;
	
	if (game->map->map[y][x + 1] == '1')
	{
		printf("CHOCAAA MAPA: %c Y: %d X: %d\n", game->map->map[y][x], y, x);
		return (0);
	}
	return (1);
}

int	ft_front_colision(t_game *game, t_player *new_coord)
{
	int	y;
	int	x;
	int	aux;;

	y = new_coord->minimap.y;
	x = new_coord->minimap.x;
	aux = x + 13;
	printf("Y: %d X: %d\n", y, x);
	//comprueba que se mueve en horizontal o vertical
	// if ((new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x == game->player->minimap.x) && (game->player->angrot == 0 || game->player->angrot == 180 || game->player->angrot == 270 || game->player->angrot == 90))
	// 	y--;
	// else if ((new_coord->minimap.y == game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x) && (game->player->angrot == 0 || game->player->angrot == 180 || game->player->angrot == 270 || game->player->angrot == 90))
	// 	x--;
	// else if (new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x)
	// 	x = (new_coord->minimap.x + 14) / 14;

	while (x < aux)
	{
		if (game->map->map[(y - 13) / 14][x / 14] == '1')
		{
			printf("CHOCAAA MAPA: %c Y: %d X: %d\n", game->map->map[y][x], y, x);
			return (0);
		}
		x++;
	}
	return (1);
}

int	ft_back_colision(t_game *game, t_player *new_coord)
{
	int	y;
	int	x;
	int	aux;;

	y = new_coord->minimap.y;
	x = new_coord->minimap.x;
	aux = x + 13;
	printf("Y: %d X: %d\n", y, x);
	while (x < aux)
	{
		if (game->map->map[y / 14][x / 14] == '1')
		{
			printf("CHOCAAA MAPA: %c Y: %d X: %d\n", game->map->map[y][x], y, x);
			return (0);
		}
		x++;
	}
	return (1);
}
int	ft_left_colision(t_game *game, t_player *new_coord)
{
	int	y;
	int	x;
	int	aux;;

	y = new_coord->minimap.y;
	x = new_coord->minimap.x;
	aux = y + 13;
	printf("Y: %d X: %d\n", y, x);
	while (y < aux)
	{
		if (game->map->map[y / 14][(x) / 14] == '1')
		{
			printf("CHOCAAA MAPA: %c Y: %d X: %d\n", game->map->map[y][x], y, x);
			return (0);
		}
		y++;
	}
	return (1);
}

int	ft_right_colision(t_game *game, t_player *new_coord)
{
	int	y;
	int	x;
	int	aux;;

	y = new_coord->minimap.y;
	x = new_coord->minimap.x;
	aux = y + 13;
	printf("Y: %d X: %d\n", y, x);
	while (y < aux)
	{
		if (game->map->map[y / 14][(x + 13) / 14] == '1')
		{
			printf("CHOCAAA MAPA: %c Y: %d X: %d\n", game->map->map[y][x], y, x);
			return (0);
		}
		y++;
	}
	return (1);
}


	// if (new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x == game->player->minimap.x)
	// {
	// 	y = new_coord->minimap.y / 14;
	// 	x = new_coord->minimap.x / 14;
	// }
	// else if (new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x)
	// {
	// MIRAR QUE CONTACTA CON LA ESQUINA SUPERIOR IZQ
	// 	y = new_coord->minimap.y / 14;
	// 	x = new_coord->minimap.x / 14;
	// }
	// else if (new_coord->minimap.y == game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x)
	// {
	// 	// MIRAR QUE CONTACTA con la izquierda
	// 	y = new_coord->minimap.y / 14;
	// 	x = new_coord->minimap.x / 14;
	// }
	// else if (new_coord->minimap.y > game->player->minimap.y && new_coord->minimap.x < game->player->minimap.x)
	// {
	// 	// MIRAR QUE CONTACTA con ESQUINA inferior izq
	// 	y = new_coord->minimap.y / 14;
	// 	x = new_coord->minimap.x / 14;
	// }
	// else if (new_coord->minimap.y > game->player->minimap.y && new_coord->minimap.x == game->player->minimap.x)
	// {
	// 	// MIRAR QUE CONTACTA abajo
	// 	y = new_coord->minimap.y / 14;
	// 	x = new_coord->minimap.x / 14;
	// }
	// else if (new_coord->minimap.y > game->player->minimap.y && new_coord->minimap.x > game->player->minimap.x)
	// {
	// 	// MIRAR QUE CONTACTA esquina inferior der
	// 	y = new_coord->minimap.y / 14;
	// 	x = new_coord->minimap.x / 14;
	// }
	// else if (new_coord->minimap.y == game->player->minimap.y && new_coord->minimap.x > game->player->minimap.x)
	// {
	// 	// MIRAR QUE CONTACTA derecha
	// 	y = new_coord->minimap.y / 14;
	// 	x = new_coord->minimap.x / 14;
	// }
	// else if (new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x > game->player->minimap.x)
	// {
	// 	// MIRAR QUE CONTACTA esquina superior derecha
	// 	y = new_coord->minimap.y / 14;
	// 	x = new_coord->minimap.x / 14;
	// }
	// else if (new_coord->minimap.y < game->player->minimap.y && new_coord->minimap.x == game->player->minimap.x)
	// {
	// 	// MIRAR QUE CONTACTA hacia arriba
	// 	y = new_coord->minimap.y / 14;
	// 	x = new_coord->minimap.x / 14;
	// }
