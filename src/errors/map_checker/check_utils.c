/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:01:25 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/02 15:30:07 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_get_len_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_get_len_x(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

char	**ft_add_extra_rows(char **map)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (ft_get_len_y(map) + 3));
	new_map[0] = ft_strdup(" ");
	while (ft_strlen(new_map[0]) < (size_t)ft_get_len_x(map))
		new_map[0] = ft_strjoin(new_map[0], " ");
	while (map[i])
	{
		new_map[i + 1] = ft_strdup(map[i]);
		i++;
	}
	new_map[i + 1] = ft_strdup(new_map[0]);
	new_map[i + 2] = NULL;
	return (new_map);
}

t_coord	ft_get_player_coord(char **map)
{
	t_coord	coord;
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				coord.x = x;
				coord.y = y;
			}
			x++;
		}
		y++;
	}
	return (coord);
}

int	ft_contains_str(char *str, char *container)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(container, str[i]))
			return (0);
		i++;
	}
	return (1);
}
