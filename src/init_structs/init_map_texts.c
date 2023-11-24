/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_texts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:35:36 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/24 16:56:25 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init_structs.h"

void	ft_init_map_textures(t_game *game)
{
	t_textures	*aux;
	int			i;

	aux = t_lstnew_texts();
	i = 1;
	while (i < 6)
	{
		ft_lstadd_back_texts(&aux, ft_lstnew_texts());
		i++;
	}
	game->map->texts = aux;
	i = 0;
	aux->id = "NO";
	aux->next->id = "SO";
	aux->next->next->id = "WE";
	aux->next->next->next->id = "EA";
	aux->next->next->next->next->id = "F";
	aux->next->next->next->next->next->id = "C";
}

static t_textures	*ft_lstnew_texts(void)
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

static t_textures	*ft_lstlast_texts(t_textures *lst)
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
