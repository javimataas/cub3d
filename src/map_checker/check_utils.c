/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:12:23 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/28 19:15:54 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube3d.h"

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
			if (map[i][j] == "\n")
				map[i][j] = " ";
	}
}