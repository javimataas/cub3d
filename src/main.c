/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:32:55 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/13 21:56:47 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_leaks(void) //ELIMINAR
{
	system("leaks -q cub3D");
}

void	ft_cub3d(t_game *game)
{
	game->mlx = mlx_init(game->final_s_width, S_HEIGHT, "Cub3D", false);
	if (!game->mlx)
		ft_error(game, ERR_MLX_FAIL);
	mlx_loop_hook(game->mlx, &ft_update, (void *)(game));
	mlx_key_hook(game->mlx, &ft_move_player, (void *)(game));
	ft_load_textures(game);
	ft_init_colormap(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_clear(game, 0);
}

int	main(int argc, char **argv)
{
	atexit(ft_leaks);
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
