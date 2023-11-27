/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:32:55 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/27 19:05:57 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc == 2)
	{
		if (ft_check_extension(argv[1]) == 0)
		{
			ft_init_map(game, argv[1]);
			ft_print_texts(game);
			// ft_print_map(game);
		}
		else
			ft_error(ERR_WRNG_EXT);
	}
	else
		ft_error(ERR_WRNG_ARGS);
	return (0);
}
