/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:53:48 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/16 16:31:18 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_coord	ft_paint_min(t_game *game, int y, int x, int color)
{
	int	i;
	int	n;
	int	ry;
	int	rx;
	t_coord	coord;

	i = -1;
	ry = 0;
	while (++i <= y)
	{
		n = -1;
		while (++n != 10)
			ry++;
	}
	i = -1;
	rx = 0;
	while (++i <= x)
	{
		n = -1;
		while (++n != 10)
			rx++;
	}
	i = -1;
	coord.x = rx;
	coord.y = ry;
	while ((ry + (++i)) < (ry + 10))
	{
		n = -1;
		while ((rx + (++n)) < (rx + 10))
			mlx_put_pixel(game->minimap->img, rx + n, ry + i, color);
	}
	return (coord);
}

void	ft_paint_elements(t_game *game)
{
	int	y;
	int	x; 

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '1')
				ft_paint_min(game, y, x, 0x000000FF);
			else if (game->map->map[y][x] == '0' || ft_strchr("NSEW", game->map->map[y][x]))
				ft_paint_min(game, y, x, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

int	ft_calc_size(t_game *game, int letter) //COMPROBAR PORQUE NO VA BIEN
{
	int	size;

	size = 0;
	if (letter == 0)
		while (game->map->map[size])
			size++;
	else if (letter == 1)
		while (game->map->map[0][size])
			size++;
	return ((size * 10) + 10); //añado +10 para que vaya bien, revisarlo bien
}

void	ft_paint_minimap(t_game *game, int img)
{
	if (img)
		mlx_delete_image(game->mlx, game->minimap->img);
	game->minimap->img = mlx_new_image(game->mlx, ft_calc_size(game, 1), ft_calc_size(game, 0)); //ft_calc_size(game, 0), ft_calc_size(game, 1)); // CALCULAR TAMAÑO QUE VA A TENER EL MAPA
	if (mlx_image_to_window(game->mlx, game->minimap->img, 0, 0) < 0) // CALCULAR DONDE EMPIEZA EL MAPA
		ft_error(game, ERR_MLX_FAIL);
	ft_paint_elements(game);
	game->minimap->img->instances[0].z = 0;
}

void	ft_init_minimap(t_game *game)
{
	ft_paint_player(game);
	ft_paint_minimap(game, 0);

}

