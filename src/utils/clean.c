/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:57 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/04 16:09:40 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_free_t_texture(t_textures *texts)
{
	t_textures	*aux;

	while (texts)
	{
		aux = texts->next;
		if (texts->path != NULL)
		{
			printf("%s\n", texts->path);
			free (texts->path);
			texts->path = NULL;
		}
		if (texts != NULL)
			free (texts);
		texts = aux;
	}
	texts = NULL;
}
void	ft_free_t_map(t_map *map)
{
	printf("A2\n");
	ft_free_t_texture(map->texts);
	printf("A3\n");
	if (map->map != NULL)
	{
		ft_free_str_array(map->map);
		map->map = NULL;
	}
	if (map != NULL)
		free (map);
	map = NULL;
}

void	ft_clear(t_game *game)
{
	printf("A1\n");
	ft_free_t_map(game->map);
	printf("A2\n");
	if (game->file != NULL)
	{
		ft_free_str_array(game->file);
		game->file = NULL;
	}
	printf("A3\n");
	if (game != NULL)
		free (game);
	game = NULL;
	printf("A4\n");
}
