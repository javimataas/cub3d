/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:43 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/16 18:51:25 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_game	*ft_init_map(char *path) // REVOSAR PORQUE CUANDO FALLAN LOS MALLOC NO LIBERO LO ANTERIOR RESERVADO
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
	game->minimap = malloc(sizeof(t_map));
	if (!game->minimap)
	{
		printf("Error: Malloc fail\n");
		free (game);
		exit (1);
	}
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		printf("Error: Malloc fail\n");
		free (game);
		exit (1);
	}
	game->map->map = NULL;
	game->file = ft_read_file(path);
			printf("FILE:\n");
			ft_print_str_array(game->file);
			printf("\n\n\n______________________\n\n\n");
	ft_init_map_textures(game);
	ft_load_struct(game);
	ft_reserve_map(game);
	ft_load_map(game);
	return (game);
}
