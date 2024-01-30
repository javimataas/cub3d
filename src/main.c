/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:32:55 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/01/30 19:42:40 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

void	ft_cub3d(t_game *game)
{
	game->mlx = mlx_init(1920, 1080, "Cub3D", false);
	if (!game->mlx)
		ft_error(game, ERR_MLX_FAIL);
	printf("Player POS: %f %f\n", game->player->player_pos.y, game->player->player_pos.x);
	mlx_loop_hook(game->mlx, &ft_update, (void *)(game));
	mlx_key_hook(game->mlx, &ft_init_hooks, (void *)(game));
	ft_load_textures(game);
	ft_init_colormap(game);
	ft_init_minimap(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_clear(game);
}

int	main(int argc, char **argv)
{
	//atexit(ft_leaks);
	t_game	*game;

	game = NULL;
	if (argc == 2)
	{
		if (ft_check_cub(argv[1]) && ft_check_file(argv[1]))
		{
			game = ft_init_map(argv[1]);
			if (ft_check_player(game)
				&& ft_check_walls(game, game->map->map))
			{
			// ft_print_texts(*game);
			// ft_print_map(game);
				ft_cub3d(game);
			}
		}
		else
			ft_error(game, ERR_WRNG_EXT);
	}
	else
		ft_error(game, ERR_WRNG_ARGS);
	return (0);
}
