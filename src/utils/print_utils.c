/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:36:56 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/30 17:20:53 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
