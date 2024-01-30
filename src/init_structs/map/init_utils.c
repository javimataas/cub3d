/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:30:49 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/30 19:46:53 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_is_empty(char *line)
{
	int		i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_texts(char *line)
{
	int		i;
	int		n;
	char	*id;

	i = 0;
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

char	**ft_read_file(char *path)
{
	char	**matrix;
	int		fd;
	char	*line;
	int		i;

	matrix = (char **)ft_calloc((ft_reserve_matrix(path) + 1), sizeof(char *)); // +1 no deberia de ser necesario
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		if (!ft_is_texts(line) && !ft_is_empty(line))
			break ;
		if (!ft_is_empty(line))
		{
			matrix[i] = ft_strdup(line);
			i++;
		}
		free (line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		matrix[i] = ft_strdup(line);
		i++;
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (matrix);
}

int	ft_reserve_matrix(char *path)
{
	char	*line;
	int		fd;
	int		len;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	len = 0;
	while (line != NULL)
	{
		if (!ft_is_texts(line) && !ft_is_empty(line))
			break ;
		if (!ft_is_empty(line))
			len++;
		free (line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		len++;
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (len);
}
