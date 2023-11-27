/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:41 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/27 18:24:13 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int		ft_is_empty(char *line)
{
	int		i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_texts(char *line)
{
	int		i;
	int		n;
	char	*id;

	i = 0;
	while (line && line[i] && (line[i] == ' ' && line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (1);
	id = (char *)ft_calloc(3, sizeof(char));
	if (!id)
		return (0);
	n = 0;
	while (line && line[i] && (line[i] != ' ' && line[i] != '\t'))
	{
		id[n] = line[i];
		n++;
		i++;
	}
	if (ft_strcmp(id, "NO") && ft_strcmp(id, "SO") && ft_strcmp(id, "WE")
		&& ft_strcmp(id, "EA") && ft_strcmp(id, "F") && ft_strcmp(id, "C"))
	{
		free (id);
		return (0);
	}
	free (id);
	return (1);
}

int	ft_check_texts(t_game *game)
{
	t_textures	*aux;

	aux = game->map->texts;
	while (aux)
	{
		if (aux->path == NULL)
			return (0);
		aux = aux->next;
	}
	return (1);
}


void	ft_load_struct(t_game *game, int fd)
{
	char		*line;

	int i = 1;
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
		printf("%d LINE: (%s)\n", i, line);
		game->map->start_map++;
		if (!ft_is_texts(line))
			break ;
		ft_select_texts(game, line);
		printf("NO ROMPE %d\n", i);
		i++;
		free (line);
		line = get_next_line(fd);
	}
	printf("NO ROMPE FINAL\n");
	// check if all texts are loaded
	if (!ft_check_texts(game))
		ft_error(ERR_MISS_TEXTS);
	ft_print_texts(game);
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
	// COMPROBAR QUE ES UN ID VALIDO Y SI NO DLLAMAR A ERROR
	while (line && line[i] && (line[i] == ' ' && line[i] == '\t'))
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
	ft_printf("%s: %s\n", aux->id, aux->path);
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
	while (n < game->map->start_map)
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
