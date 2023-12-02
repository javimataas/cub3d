/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:57 by jariza-o          #+#    #+#             */
/*   Updated: 2023/12/02 18:50:21 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_clear(t_game *game)
{
	t_textures	*aux ;

	aux = game->map->texts;
	while (aux)
	{
		if (aux->id != NULL)
			free (aux->id);
		if (aux->path != NULL)
			free (aux->path);
		aux = aux->next;
	}
	free (game->map->texts);
	if (game->map->map != NULL)
		ft_free_str_array(game->map->map);
	free (game->map);
	if (game->file != NULL)
		ft_free_str_array(game->file);
	if (game != NULL)
		free (game);
	mlx_terminate(game->mlx);
}
