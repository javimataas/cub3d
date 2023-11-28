/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:41 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/28 16:37:04 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_load_struct(t_game *game, int fd)
{
	char		*line;

	line = get_next_line(fd);
	game->map->start_map = 0;
	while (line != NULL)
	{
		while (line != NULL && ft_is_empty(line) == 0)
		{
			free (line);
			line = get_next_line(fd);
			game->map->start_map++;
		}
		game->map->start_map++;
		if (!ft_is_texts(line))
			break ;
		ft_select_texts(game, line);
		free (line);
		line = get_next_line(fd);
	}
	if (!ft_check_texts(game))
		ft_error(ERR_MISS_TEXTS);
	if (line != NULL)
		free (line);
}

void	ft_select_texts(t_game *game, char *line) // como estoy uasnado aux no dbería de perderse la referencia
{
	int			i;
	int			n;
	char		*id;
	int			len;
	t_textures	*aux;

	i = 0;
	while (line && line[i] && (line[i] == ' ' && line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n') //Por si hay lineas vacias
		return ;
	id = (char *)ft_calloc(3, sizeof(char));
	if (!id)
		return ;
	n = 0;
	while (line && line[i] && (line[i] != ' ' && line[i] != '\t'))
	{
		id[n] = line[i];
		n++;
		i++;
	}
	while (line && line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		ft_error(ERR_EMPT_TEXTS);
	len = 0;
	n = i;
	while (line && line[i])
	{
		i++;
		len++;
	}
	aux = game->map->texts;
	while (aux && ft_strcmp(id, aux->id))
		aux = aux->next;
	if (aux && aux->path != NULL)
		ft_error(ERR_DUP_TEXTS);
	aux->path = (char *)ft_calloc((len + 1), sizeof(char));
	if (!aux->path)
		return ;
	i = 0;
	while (line && line[n])
	{
		aux->path[i] = line[n];
		i++;
		n++;
	}
	free (id);
}

void	ft_reserve_map(t_game *game, char *path)
{
	int		fd;
	int		i;
	int		len_line;
	char	*line;

	fd = open(path, O_RDONLY);
	i = 0; // Lo he puesto a 1 porque sino fallaba y se pasaba una linea del inicio del mapa
	len_line = 0;
	line = get_next_line(fd);
	while (i < game->map->start_map)
	{
		free (line);
		line = get_next_line(fd);
		i++;
	}
	while (line != NULL)
	{
		if (!ft_is_empty(line))
			game->map->start_map++;
		else
			break ;
		free (line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		if (!ft_is_empty(line))
			break ;
		len_line++;
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	game->map->map = (char **)ft_calloc((len_line + 1), sizeof (char *));
	if (!game->map->map)
		return ;
}

void	ft_load_map(t_game *game, char *path)
{
	int		fd;
	int		i;
	int		n;
	char	*line;

	fd = open(path, O_RDONLY);
	n = 0; // estaba a 0
	line = get_next_line(fd);
	while (n < game->map->start_map)
	{
		n++;
		free (line);
		line = get_next_line(fd);
	}
	i = 0;
	while (line != NULL)
	{
		if (!ft_is_empty(line))
			break ;
		game->map->map[i] = ft_strdup(line);
		i++;
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
}
