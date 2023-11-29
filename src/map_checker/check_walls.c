/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:12:23 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/29 17:29:54 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_char_count(char **map, char c)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

void	ft_flood_fill(char **map, int begin_y, int begin_x)
{
	if (map[begin_y][begin_x] == '1' || map[begin_y][begin_x] == 'F'
		|| map[begin_y][begin_x] == '\0')
		return ;
	if (begin_y <= 0 || begin_x < 0 || begin_y >= ft_get_len_y(map) - 1
		|| (unsigned int)begin_x > ft_strlen(map[begin_y]))
		return ;
	map[begin_y][begin_x] = 'F';
	ft_flood_fill(map, begin_y - 1, begin_x);
	ft_flood_fill(map, begin_y + 1, begin_x);
	ft_flood_fill(map, begin_y, begin_x - 1);
	ft_flood_fill(map, begin_y, begin_x + 1);
}

void	ft_space_map(char **map)
{
	char	*aux;
	char	*space;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		space = ft_strdup(" ");
		aux = ft_strdup(map[i]);
		free(map[i]);
		map[i] = ft_strjoin(space, aux);
		free(aux);
		i++;
	}
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j] == '\n')
				map[i][j] = ' ';
	}
}

int	ft_walls(char **map)
{
	t_coord	coord;
	int		valid;
	int		y;
	int		x;
	char	**aux;

	ft_space_map(map);
	aux = ft_copy_str_array(map);
	ft_free_str_array(map);
	map = ft_add_extra_rows(aux);
	ft_free_str_array(aux);
	valid = ft_char_count(map, ' ');
	coord = ft_get_player_coord(map);
	y = coord.y;
	x = coord.x;
	ft_flood_fill(map, y, x);
	if (ft_char_count(map, ' ') != valid || !ft_contains_str(map[1], "1 \n")
		|| !ft_contains_str(map[ft_get_len_y(map) - 2], "1 \n")
		|| ft_char_count(map, '0'))
	{
		ft_free_str_array(map);
		return (2);
	}
	ft_free_str_array(map);
	return (1);
}

int	ft_check_walls(char **map)
{
	int	i;

	i = ft_walls(map);
	if (i == 2)
	{
		map = NULL;
		ft_error(ERR_MAP_FAIL);
		return (0);
	}
	if (i == 0)
	{
		ft_free_str_array(map);
		map = NULL;
		ft_error(ERR_MAP_FAIL);
		return (0);
	}
	map = NULL;
	return (1);
}
