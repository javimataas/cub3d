/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:36:17 by jmatas-p          #+#    #+#             */
/*   Updated: 2024/02/13 22:37:18 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_if_png_exist(t_game *game)
{
	int			fd;
	int			i;
	t_textures	*aux;

	i = 0;
	aux = game->map->texts;
	while (aux && i <= 3)
	{
		fd = open(aux->path, O_RDONLY);
		if (fd == -1)
		{
			close (fd);
			return (ft_error(game, ERR_DUP_TEXTS));
		}
		close (fd);
		aux = aux->next;
		i++;
	}
}

void	ft_load_game_textures(t_game *game)
{
	ft_check_if_png_exist(game);
	game->textures = ft_calloc(sizeof(mlx_texture_t *), 4);
	if (!ft_check_png(game->map->texts->path))
		return (ft_error(game, ERR_DUP_TEXTS_2));
	game->textures[0] = mlx_load_png(game->map->texts->path);
	if (!ft_check_png(game->map->texts->next->path))
		return (ft_error(game, ERR_DUP_TEXTS_2));
	game->textures[1] = mlx_load_png(game->map->texts->next->path);
	if (!ft_check_png(game->map->texts->next->next->path))
		return (ft_error(game, ERR_DUP_TEXTS_2));
	game->textures[2] = mlx_load_png(game->map->texts->next->next->path);
	if (!ft_check_png(game->map->texts->next->next->next->path))
		return (ft_error(game, ERR_DUP_TEXTS_2));
	game->textures[3] = mlx_load_png(game->map->texts->next->next->next->path);
	if (game->textures[0] == NULL || game->textures[1] == NULL
		|| game->textures[2] == NULL || game->textures[3] == NULL)
		return (ft_error(game, ERR_MLX_FAIL));
}
