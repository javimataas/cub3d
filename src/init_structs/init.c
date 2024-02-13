/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:43 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/13 22:42:01 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_sizes(t_game *game)
{
	game->pov_ang = 60 * DEF;
	if (S_WIDTH < game->pov_ang * 1.5)
		game->final_s_width = game->pov_ang;
	else if (S_WIDTH < game->pov_ang * 2.5 && S_WIDTH >= game->pov_ang
		* 1.5)
		game->final_s_width = game->pov_ang * 2;
	else if (S_WIDTH < game->pov_ang * 3.5 && S_WIDTH >= game->pov_ang
		* 2.5)
		game->final_s_width = game->pov_ang * 3;
	else
		game->final_s_width = game->pov_ang * 4;
}

void	ft_set_map_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map->height = 0;
	game->map->width = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
			j++;
		if (j > game->map->width)
			game->map->width = j;
		i++;
	}
	game->map->height = i;
}

void	free_game_structures(t_game *game)
{
	free(game->player);
	free(game->map);
	free(game);
}

t_game	*allocate_game_structures(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		printf("Error: Malloc fail\n");
		exit(1);
	}
	game->file = NULL;
	game->map = malloc(sizeof(t_map));
	game->player = malloc(sizeof(t_player));
	if (!game->map || !game->player)
	{
		printf("Error: Malloc fail\n");
		free_game_structures(game);
		exit(1);
	}
	game->map->map = NULL;
	return (game);
}

t_game	*ft_init_map(char *path)
{
	t_game	*game;

	game = allocate_game_structures();
	game->file = ft_read_file(path);
	ft_init_sizes(game);
	game->rays = malloc(sizeof(t_rays) * game->pov_ang);
	ft_init_map_textures(game);
	ft_load_struct(game);
	ft_load_game_textures(game);
	ft_reserve_map(game);
	ft_load_map(game);
	ft_set_map_size(game);
	return (game);
}
