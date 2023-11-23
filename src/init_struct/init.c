/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:43 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/23 17:42:11 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h" //crear .h

void	ft_init_struct(t_game *game, char **argv)
{
	game->map_path = ft_strdup(argv[1]);
	ft_init_map_textures(t_game *game);
	
}

void	ft_init_map_textures(t_game *game)
{
	game->textures[]
}