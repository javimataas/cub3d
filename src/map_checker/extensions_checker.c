/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extensions_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:29:43 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/30 18:56:09 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_cub(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 'b' && file[i - 2] == 'u'
		&& file[i - 3] == 'c' && file[i - 4] == '.' && file[i - 5])
		return (1);
	return (0);
}

int	ft_check_png(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 'g' && file[i - 2] == 'n'
		&& file[i - 3] == 'p' && file[i - 4] == '.' && file[i - 5])
		return (1);
	return (0);
}
