/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:01:14 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/11 10:59:21 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*ft_get_id(t_game *game, char *line, int *i)
{
	int		n;
	char	*id;

	if (!ft_check_id(line))
	{
		printf("JBHJBHJBJ\n");
		ft_error(game, ERR_WRNG_ID);
	}
	ft_printf("rrrrrr\n");
	id = (char *)ft_calloc(3, sizeof(char));
	if (!id)
		return (NULL);
	n = 0;
	while (line && line[(*i)] && (line[(*i)] == ' ' || line[(*i)] == '\t'))
		(*i)++;
	while (n < 2 && line && line[(*i)] && (line[(*i)] != ' ' && line[(*i)] != '\t'))
	{
		id[n] = line[(*i)];
		printf("ID N: %c\n", id[n]);
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

void	ft_assign_aux(t_textures *aux, char *lin, int *n)
{
	int	i;

	i = 0;
	while (lin && lin[(*n)] && (lin[(*n)] != '\n' && lin[(*n)] != '\0'))
	{
		aux->path[i] = lin[(*n)];
		i++;
		(*n)++;
	}
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
	ft_printf("JHJreergergrgerrgdgfdgdfgdfg\n");
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
	ft_assign_aux(aux, line, &n);
	free (id);
}
