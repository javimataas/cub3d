/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:41 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/07 23:12:53 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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

char	*ft_get_id(t_game *game, char *line, int *i)
{
	int		n;
	char	*id;

	if (!ft_check_id(line))
		ft_error(game, ERR_WRNG_ID);
	id = (char *)ft_calloc(3, sizeof(char));
	if (!id)
		return (NULL);
	n = 0;
	while (line && line[(*i)] && (line[(*i)] == ' ' || line[(*i)] == '\t'))
		(*i)++;
	while (line && line[(*i)] && (line[(*i)] != ' ' && line[(*i)] != '\t'))
	{
		id[n] = line[(*i)];
		n++;
		(*i)++;
	}
	return (id);
}

int	ft_get_len(char *line, int *i)
{
	int	len;

	len = 0;
	while (line && line[(*i)])
	{
		(*i)++;
		len++;
	}
	return (len);
}

void	ft_select_texts(t_game *game, char *line)
{
	int			i;
	int			n;
	char		*id;
	int			len;
	t_textures	*aux;

	i = 0;
	id = ft_get_id(game, line, &i);
	while (line && line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		ft_error(game, ERR_EMPT_TEXTS);
	n = i;
	len = ft_get_len(line, &i);
	aux = game->map->texts;
	while (aux && ft_strcmp(id, aux->id))
		aux = aux->next;
	if (aux && aux->path != NULL)
		ft_error(game, ERR_DUP_TEXTS);
	aux->path = (char *)ft_calloc((len + 1), sizeof(char));
	if (!aux->path)
		return ;
	i = 0;
	while (line && line[n] && (line[n] != '\n' && line[n] != '\0'))
	{
		aux->path[i] = line[n];
		i++;
		n++;
	}
	free (id);
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
