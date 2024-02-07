/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:49:36 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/07 16:53:16 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_walls(char **map)
{
	t_coord	coord;
	t_coord	floor;
	int		valid;
	int		y;
	int		x;
	char	**aux;

	ft_space_map(map);
	aux = ft_copy_str_array(map);
	ft_free_str_array(map);
	map = NULL;
	map = ft_add_extra_rows(aux);
	ft_free_str_array(aux);
	aux = NULL;
	valid = ft_char_count(map, ' ');
	coord = ft_get_player_coord(map);
	y = coord.y;
	x = coord.x;
	ft_flood_fill(map, y, x);
	floor = ft_has_floor(map);
	while (floor.x != 0 && floor.y != 0)
	{
		ft_flood_fill(map, floor.y, floor.x);
		floor = ft_has_floor(map);
	}
	if (ft_char_count(map, ' ') != valid || !ft_contains_str(map[1], "1 \n")
		|| !ft_contains_str(map[ft_get_len_y(map) - 2], "1 \n"))
	{
		ft_free_str_array(map);
		map = NULL;
		return (2);
	}
	ft_free_str_array(map);
	return (1);
}

int	ft_check_walls(t_game *game, char **map)
{
	int		i;
	char	**aux;

	aux = ft_copy_str_array(map);
	i = ft_walls(aux);
	if (i == 2)
		ft_error(game, ERR_MAP_FAIL);
	return (1);
}
