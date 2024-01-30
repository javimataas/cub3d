/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_texts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:35:36 by jariza-o          #+#    #+#             */
/*   Updated: 2024/01/15 19:02:14 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_init_map_textures(t_game *game)
{
	t_textures	*aux;
	int			i;

	aux = ft_lstnew_texts();
	i = 1;
	while (i < 6)
	{
		ft_lstadd_back_texts(&aux, ft_lstnew_texts());
		i++;
	}
	aux->id = "NO";
	aux->next->id = "SO";
	aux->next->next->id = "WE";
	aux->next->next->next->id = "EA";
	aux->next->next->next->next->id = "F";
	aux->next->next->next->next->next->id = "C";
	aux->next->next->next->next->next->next = NULL;
	game->map->texts = aux;
}

t_textures	*ft_lstnew_texts(void)
{
	t_textures	*node;

	node = (t_textures *)malloc(sizeof(t_textures));
	if (node == NULL)
		return (NULL);
	node->id = NULL;
	node->path = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_textures	*ft_lstlast_texts(t_textures *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_texts(t_textures **lst, t_textures *new)
{
	if (*lst)
	{
		new->prev = ft_lstlast_texts(*lst);
		ft_lstlast_texts(*lst)->next = new;
	}
}
