/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:32:55 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/21 18:40:48 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_check_extension(argv[1]) == 0)
			//ft_map_checker(argv[1]); TODO
			printf("TODO\n");
		else
			return (ft_error(ERR_WRNG_EXT));
	}
	else
		return (ft_error(ERR_WRNG_ARGS));
	return (0);
}
