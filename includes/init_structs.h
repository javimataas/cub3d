/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:23:00 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/26 17:01:46 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_STRUCTS_H
# define INIT_STRUCTS_H

# include "cub3d.h"
# include <fcntl.h>

/* INIT */

/* INIT_STRUCT */
void		ft_init_map(t_game *game, char *path);

/* Create t_textures */
void		ft_init_map_textures(t_game *game);
t_textures	*ft_lstnew_texts(void);
t_textures	*ft_lstlast_texts(t_textures *lst);
void		ft_lstadd_back_texts(t_textures **lst, t_textures *new);

/* Load Textures in Struct */
void		ft_load_struct(t_game *game, int fd);
void		ft_select_texts(t_game *game, char *line);

/* Load Map */
void		ft_reserve_map(t_game *game, char *path);
void		ft_load_map(t_game *game, char *path);

#endif