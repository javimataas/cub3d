/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:43 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/14 17:29:15 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_game	*ft_init_map(char *path)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		printf("Error: Malloc fail\n");
		exit (1);
	}
	game->file = NULL;
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		printf("Error: Malloc fail\n");
		free (game);
		exit (1);
	}
	game->player = malloc(sizeof(t_coord));
	if (!game->map)
	{
		printf("Error: Malloc fail\n");
		free (game);
		exit (1);
	}
	game->map->map = NULL;
	game->file = ft_read_file(path);
	ft_init_map_textures(game);
	ft_load_struct(game);
	ft_reserve_map(game);
	ft_load_map(game);
	return (game);
}
