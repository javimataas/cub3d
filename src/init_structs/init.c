/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:43 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/26 17:57:30 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init_structs.h"

void	ft_init_map(t_game *game, char *path)
{
	int	fd;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		ft_error(ERR_MLLC_FAIL);
		return ;
	}
	fd = open(path, O_RDONLY);
	ft_init_map_textures(game);
	ft_load_struct(game, fd);
	close(fd);
	ft_reserve_map(game, path);
	ft_load_map(game, path);
}
