/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:36:56 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/08 22:10:04 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	ft_print_texts(t_game game)
{
	ft_printf("---------Textures-----------\n");
	ft_printf("%s: %s\n", game.map->texts->id, game.map->texts->path);
	ft_printf("%s: %s\n", game.map->texts->next->id,
		game.map->texts->next->path);
	ft_printf("%s: %s\n", game.map->texts->next->next->id,
		game.map->texts->next->next->path);
	ft_printf("%s: %s\n", game.map->texts->next->next->next->id,
		game.map->texts->next->next->next->path);
	ft_printf("%s: %s\n", game.map->texts->next->next->next->next->id,
		game.map->texts->next->next->next->next->path);
	ft_printf("%s: %s\n", game.map->texts->next->next->next->next->next->id,
		game.map->texts->next->next->next->next->next->path);
	ft_printf("----------------------------\n");
}

void	ft_print_map(t_game *game)
{
	int	i;

	i = 0;
	ft_printf("-----------MAP---------------\n");
	while (game->map->map[i])
	{
		ft_printf("%s", game->map->map[i]);
		i++;
	}
	ft_printf("\n--------------------------\n");
}
