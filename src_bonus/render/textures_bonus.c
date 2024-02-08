/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:07:15 by jariza-o          #+#    #+#             */
/*   Updated: 2024/02/08 22:10:16 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	check_rgb_values(t_game *game, char **numbers)
{
	int	i;
	int	n;

	i = -1;
	while (numbers && numbers[++i])
	{
		n = ft_atoi(numbers[i]);
		if (n < 0 || n > 255)
		{
			ft_free_str_array(numbers);
			ft_error(game, ERR_COLOR_FAIL);
		}
	}
}

void	ft_check_rgb(t_game *game, t_textures *texts)
{
	char	**numbers;
	int		i;
	int		n;

	numbers = ft_split(texts->path, ',');
	i = -1;
	while (numbers && numbers[++i])
	{
		n = -1;
		while (numbers[i][++n])
		{
			if (numbers[i][n] != '\n' && !ft_isdigit(numbers[i][n]))
			{
				ft_free_str_array(numbers);
				ft_error(game, ERR_COLOR_FAIL);
			}
		}
	}
	check_rgb_values(game, numbers);
	ft_free_str_array(numbers);
}

static void	ft_check_pngpath(t_game *game)
{
	t_textures	*aux;

	aux = game->map->texts;
	while (aux)
	{
		if (ft_check_png(aux->path) && (ft_strcmp(aux->id, "F")
				&& ft_strcmp(aux->id, "C")))
			ft_error(game, ERR_PNG_FAIL);
		if (!ft_strcmp(aux->id, "F") || !ft_strcmp(aux->id, "C"))
			ft_check_rgb(game, aux);
		aux = aux->next;
	}
}

void	ft_load_textures(t_game *game)
{
	t_textures		*aux;
	mlx_texture_t	*text;

	aux = game->map->texts;
	ft_check_pngpath(game);
	while (aux && (ft_strcmp(aux->id, "F") && ft_strcmp(aux->id, "C")))
	{
		text = mlx_load_png(aux->path);
		if (!text)
			ft_error(game, 404);
		aux->image = mlx_texture_to_image(game->mlx, text);
		mlx_delete_texture(text);
		aux = aux->next;
	}
}
