/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:57 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/08 19:01:55 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_mlx_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4 && game->textures[i])
	{
		ft_printf("%s\n", game->textures[i]);
		mlx_delete_texture(game->textures[i]);
		game->textures[i] = NULL;
	}
	if (game->textures != NULL)
		free (game->textures);
}

void	ft_free_t_texture(t_textures *texts)
{
	t_textures	*aux;

	while (texts)
	{
		aux = texts->next;
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

void	ft_clear(t_game *game, int flag)
{
	ft_free_t_map(game->map);
	if (!flag)
		ft_free_mlx_textures(game);
	if (game->rays != NULL)
		free (game->rays);
	if (game->minimap != NULL)
		free (game->minimap);
	if (game->animation != NULL)
		free (game->animation);
	if (game->player != NULL)
		free (game->player);
	if (game->file != NULL)
	{
		ft_free_str_array(game->file);
		game->file = NULL;
	}
	if (game != NULL)
		free (game);
	game = NULL;
}
