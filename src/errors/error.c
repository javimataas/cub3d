/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:21:05 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/13 15:46:18 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_error_2(int error, int *flag);

void	ft_texts_error(int *flag, char *error)
{
	*flag = 1;
	ft_printf("%s", error);
}

void	ft_error(t_game *game, int error)
{
	int	flag;

	flag = 0;
	if (error == ERR_WRNG_ARGS)
	{
		printf("Error: Wrong number of arguments\n");
		exit(1);
	}
	else if (error == ERR_WRNG_EXT)
	{
		printf("Error: Wrong file\n");
		exit(1);
	}
	else if (error == ERR_MLLC_FAIL)
		printf("Error: Malloc fail\n");
	else if (error == ERR_DUP_TEXTS_2)
		printf("Error: A coordenate texture not is correct\n");
	else if (error == ERR_DUP_TEXTS)
		ft_texts_error(&flag, "Error: A coordenate texture not is correct\n"); // DA LEAKS CUANDO intanta cargar y va mal
	else if (error == ERR_MISS_TEXTS || error == ERR_WRNG_ID)
		ft_texts_error(&flag, "Error: A coordenate texture is missing\n");
	else if (error == ERR_EMPT_TEXTS)
		printf("Error: A path texture is empty\n");
	else
		ft_error_2(error, &flag);
	ft_clear(game, flag);
	exit(1);
}

static void	ft_error_2(int error, int *flag)
{
	if (error == ERR_PNG_FAIL)
		ft_texts_error(flag, "Error: The texture file ins't .png");
	else if (error == ERR_MLX_FAIL)
		printf("Error: MLX fail\n");
	else if (error == ERR_MAP_FAIL)
		printf("Error: Invalid map\n");
	else if (error == ERR_NO_PLAYER)
		printf("Error: No player found in the map\n");
	else if (error == ERR_COLOR_FAIL)
		printf("Error: The color for the texture is incorrect");
}
