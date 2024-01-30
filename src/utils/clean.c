/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:57 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/10 17:23:22 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_mlx_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->textures[i] != NULL)
		{
			mlx_delete_texture(game->textures[i]);
			game->textures[i] = NULL;
		}
		i++;
	}
}

void	ft_free_t_texture(t_textures *texts)
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
	ft_free_t_texture(map->texts);
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
	ft_free_t_map(game->map);
	ft_free_mlx_textures(game);
	if (game->file != NULL)
	{
		ft_free_str_array(game->file);
		game->file = NULL;
	}
	if (game != NULL)
		free (game);
	game = NULL;
}
