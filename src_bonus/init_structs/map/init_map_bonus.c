/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:41 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/13 08:30:53 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/cub3d_bonus.h"

void	ft_load_struct(t_game *game)
{
	int	i;

	i = 0;
	while (game->file[i])
	{
		if (ft_is_empty(game->file[i]))
		{
			i++;
		}
		else
		{
			if (!ft_is_texts(game->file[i]))
				break ;
			ft_select_texts(game, game->file[i]);
			i++;
		}
	}
	game->map->start_map = i;
	if (!ft_check_texts(game))
		ft_error(game, ERR_MISS_TEXTS);
}

int	ft_check_id(char *line)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (line && line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line && line[i] && (line[i] != ' ' && line[i] != '\t'))
	{
		i++;
		n++;
	}
	if (n > 2)
		return (0);
	return (1);
}

void	ft_reserve_map(t_game *game)
{
	int		i;
	int		len_line;

	i = game->map->start_map;
	len_line = 0;
	while (game->file[i])
	{
		len_line++;
		i++;
	}
	game->map->map = (char **)ft_calloc((len_line + 1), sizeof (char *));
	if (!game->map->map)
		ft_error(game, ERR_MLLC_FAIL);
}

void	ft_load_map(t_game *game)
{
	int		i;
	int		n;

	n = game->map->start_map;
	i = 0;
	while (game->file[n])
	{
		game->map->map[i] = ft_strdup(game->file[n]);
		i++;
		n++;
	}
}
