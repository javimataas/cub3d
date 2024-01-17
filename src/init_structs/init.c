/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:43 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/17 18:41:32 by jmatas-p         ###   ########.fr       */
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

void	ft_load_game_textures(t_game *game)
{
	game->textures = ft_calloc(sizeof(mlx_texture_t *), 4);
	game->textures[0] = mlx_load_png(game->map->texts->path);
	game->textures[1] = mlx_load_png(game->map->texts->next->path);
	game->textures[2] = mlx_load_png(game->map->texts->next->next->path);
	game->textures[3] = mlx_load_png(game->map->texts->next->next->next->path);
	if (game->textures[0] == NULL || game->textures[1] == NULL
		|| game->textures[2] == NULL || game->textures[3] == NULL)
		return (ft_error(game, ERR_MLX_FAIL));
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
