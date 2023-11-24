/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:23:00 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/24 17:13:07 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_STRUCTS_H
# define INIT_STRUCTS_H

# include "cub3d.h"
# include <fcntl.h>

/* INIT */

/* INIT_MAP */


/* Create t_textures */
void				ft_init_map_textures(t_game *game);
static t_textures	*ft_lstnew_texts(void);
static t_textures	*ft_lstlast_texts(t_textures *lst);
void				ft_lstadd_back_texts(t_textures **lst, t_textures *new);

#endif