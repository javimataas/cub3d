/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:21:05 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/29 17:26:31 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_error(int error)
{
	if (error == ERR_WRNG_ARGS)
		printf("Error: Wrong number of arguments\n");
	else if (error == ERR_WRNG_EXT)
		printf("Error: Wrong file extension\n");
	else if (error == ERR_MLLC_FAIL)
		printf("Error: Malloc fail\n");
	else if (error == ERR_DUP_TEXTS)
		printf("Error: A coordenate texture is duplicated\n");
	else if (error == ERR_MISS_TEXTS)
		printf("Error: A coordenate texture is missing\n");
	else if (error == ERR_EMPT_TEXTS)
		printf("Error: A path texture is empty\n");
	else if (error == ERR_MLX_FAIL)
		printf("Error: MLX fail\n");
	else if (error == ERR_MAP_FAIL)
		printf("Error: Invalid map\n");
	else if (error == ERR_NO_PLAYER)
		printf("Error: No player found in the map\n");
	exit (1);
}
