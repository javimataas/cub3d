/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:43 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/28 17:11:49 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_game	*ft_init_map(char *path)
{
	t_game	*game;
	int		fd;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error(ERR_MLLC_FAIL);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		ft_error(ERR_MLLC_FAIL);
	game->map->file = ft_read_file(path);
	fd = open(path, O_RDONLY);
	ft_init_map_textures(game);
	ft_load_struct(game, fd);
	close(fd);
	ft_reserve_map(game, path);
	ft_load_map(game, path);
	return (game);
}
