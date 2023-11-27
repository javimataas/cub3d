/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:21:05 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/27 18:24:59 by jmatas-p         ###   ########.fr       */
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
	exit (1);
}
