/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:41 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/26 17:56:03 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_structs.h"

void	ft_load_struct(t_game *game, int fd)
{
	char		*line;

	line = get_next_line(fd);
	game->map->start_map = 0;
	while (line != NULL)
	{
		ft_select_texts(game, line);
		game->map->start_map++;
		free (line);
		//COMPROBAR SI TENEMOS TODAS LAS TEXTURAS y SALIR
		line = get_next_line(fd);
	}
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
	while (line && line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0') //Por si hay lineas vacias
		return ;
	id = (char *)ft_calloc(3, sizeof(char));
	if (!id)
		return ;
	n = 0;
	while (line && line[i] && (line[i] != ' ' || line[i] != '\t'))
	{
		id[n] = line[i];
		n++;
		i++;
	}
	// COMPROBAR QUE ES UN ID VALIDO Y SI NO DLLAMAR A ERROR
	while (line && line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
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
	if (aux->path != NULL)
		return ; //LlAMAR A ERROR
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
	i = 0;
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
		i = 0;
		while (line && line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] == '\n')
			game->map->start_map++;
		else
			break ;
		free (line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		i = 0;
		while (line && line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] == '\n' || line[i] == '\n')
			break ;
		len_line++;
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
	n = 0;
	line = get_next_line(fd);
	while (n < game->map->map)
	{
		n++;
		free (line);
		line = get_next_line(fd);
	}
	i = 0;
	while (line != NULL)
	{
		n = 0;
		while (line && line[n] && (line[n] == ' ' || line[n] == '\t'))
			n++;
		if (line[i] == '\n' || line[i] == '\0')
			break ;
		game->map->map[i] = ft_strdup(line);
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
}
