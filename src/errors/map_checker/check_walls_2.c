/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:49:36 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/08 20:47:36 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_prepare_map(char ***map)
{
	char	**aux;

	ft_space_map(*map);
	aux = ft_copy_str_array(*map);
	ft_free_str_array(*map);
	*map = NULL;
	*map = ft_add_extra_rows(aux);
	ft_free_str_array(aux);
	aux = NULL;
}

int	ft_walls(char **map)
{
	t_coord	coord;
	t_coord	floor;
	int		valid;
	int		y;
	int		x;

	ft_prepare_map(&map);
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
		return (ft_free_str_array(map), map = NULL, 2);
	return (ft_free_str_array(map), 1);
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
