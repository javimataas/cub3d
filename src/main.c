/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:32:55 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/29 17:33:32 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		if (ft_check_extension(argv[1]) == 0)
		{
			printf("BUCLE");
			game = ft_init_map(argv[1]);
			if (ft_check_walls(game->map->map)
				&& ft_check_player(game->map->map))
			{
				ft_print_texts(*game);
				ft_print_map(game);
				game->mlx = mlx_init(1920, 1080, "Cub3D", true);
				if (!game->mlx)
					ft_error(ERR_MLX_FAIL);
				mlx_key_hook(game->mlx, &escape_hook, (void *)(game));
				mlx_resize_hook(game->mlx, &hook_screen, (void *)(game));
				mlx_loop(game->mlx);
			}
		}
		else
			ft_error(ERR_WRNG_EXT);
	}
	else
		ft_error(ERR_WRNG_ARGS);
	return (0);
}
