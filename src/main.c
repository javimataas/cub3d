/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:32:55 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/07 19:40:03 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

void	ft_cub3d(t_game *game)
{
	game->mlx = mlx_init(game->final_s_width, S_HEIGHT, "Cub3D", false);
	if (!game->mlx)
		ft_error(game, ERR_MLX_FAIL);
	mlx_loop_hook(game->mlx, &ft_update, (void *)(game));
	mlx_scroll_hook(game->mlx, &my_scrollhook, (void *)(game));
	mlx_key_hook(game->mlx, &ft_move_player, (void *)(game));
	ft_load_textures(game);
	ft_init_colormap(game);
	ft_init_minimap(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_clear(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc == 2)
	{
		if (ft_check_cub(argv[1]) && ft_check_file(argv[1]))
		{
			game = ft_init_map(argv[1]);
			if (ft_check_player(game)
				&& ft_check_walls(game, game->map->map))
				ft_cub3d(game);
		}
		else
			ft_error(game, ERR_WRNG_EXT);
	}
	else
		ft_error(game, ERR_WRNG_ARGS);
	return (0);
}
