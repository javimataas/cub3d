/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:32:55 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/02 18:40:16 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

void	ft_cub3d(t_game *game)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	game->mlx = mlx_init(1920, 1080, "Cub3D", true);
	if (!game->mlx)
		ft_error(game, ERR_MLX_FAIL);
	ft_load_textures(game);
}

int	main(int argc, char **argv)
{
	atexit(ft_leaks);
	t_game	*game;

	game = NULL;
	if (argc == 2)
	{
		if (ft_check_cub(argv[1]))
		{
			game = ft_init_map(argv[1]);
			if (ft_check_player(game)
				&& ft_check_walls(game, game->map->map))
			{
				ft_print_texts(*game);
				ft_print_map(game);
				ft_cub3d(game);
				mlx_key_hook(game->mlx, &escape_hook, (void *)(game));
				mlx_resize_hook(game->mlx, &hook_screen, (void *)(game));
				mlx_loop(game->mlx);
			}
		}
		else
			ft_error(game, ERR_WRNG_EXT);
	}
	else
		ft_error(game, ERR_WRNG_ARGS);
	return (0);
}
