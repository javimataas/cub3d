/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:23:20 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/30 22:42:05 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_pixel(t_game *game)
{
	t_textures	*aux;
	char		**rgb;

	aux = game->map->texts;
	rgb = NULL;
	while (aux)
	{
		if (ft_strchr("FC", aux->id[0]))
		{
			rgb = ft_split(aux->path, ',');
			aux->color = (ft_atoi(rgb[0]) << 24 | ft_atoi(rgb[1]) << 16 | ft_atoi(rgb[2]) << 8 | 0xFF);
			if (rgb != NULL)
				ft_free_str_array(rgb);
			rgb = NULL;
		}
		aux = aux->next;
	}
}
