/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:30:36 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/23 17:32:28 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/read_map.h"

void	ft_map_textures(t_game *game, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line && line != NULL)
	{
		i = 0;
		while (line && line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] == 'N' && line[i + 1] == 'O')
			game->textures[0] = "NO";
		else if (line[i] == 'S' && line[i + 1] == 'O')
			game->textures[1] = "SO";
		else if (line[i] == 'W' && line[i + 1] == 'E')
			game->textures[1] = "WE";
		else if (line[i] == 'E' && line[i + 1] == 'A')
			game->textures[3] = "SO";
		else if (line[i] == 'F')
			game->textures[4] = "F";
		else if (line[i] == 'C')
			game->textures[5] = "C";
	}

}
