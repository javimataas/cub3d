/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:57 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/07 18:37:49 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_mlx_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
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
		// ID NO SE LIBERA PORQUE ESTA A CASCOPPORRO
		if (texts->path != NULL)
		{
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
