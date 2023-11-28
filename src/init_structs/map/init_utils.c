/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:30:49 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/28 15:34:25 by jariza-o         ###   ########.fr       */
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
