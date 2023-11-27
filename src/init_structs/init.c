/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:43 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/27 19:32:19 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_map(t_game *game, char *path)
{
	int	fd;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_error(ERR_MLLC_FAIL);
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
		ft_error(ERR_MLLC_FAIL);
	fd = open(path, O_RDONLY);
	ft_init_map_textures(game);
	ft_load_struct(game, fd);
	close(fd);
	ft_reserve_map(game, path);
	ft_load_map(game, path);
	ft_print_texts(game);
}
