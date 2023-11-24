/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:41 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/24 17:23:35 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init_structs.h"

void	ft_init_map(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	ft_init_map_textures(game);
	ft_load_struct()

}

void	ft_load_struct(t_game *game, int fd)
{
	char		*line;
	int			i;
	t_textures	*aux;

	line = get_next_line(fd);
	aux = game->map->texts;
	while (line != NULL)
	{
		i = 0;
		while (line && line[i])
		{
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			// BUCLE PARA MOVER T_TEXTURES MIENTRA NO ESTE EN EL ID CORRECTO
			// ASIGNAR PATH
			
		}
	}
}