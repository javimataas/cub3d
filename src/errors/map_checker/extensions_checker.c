/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extensions_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:29:43 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/12/02 15:30:13 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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
	if (file[i] == 'g' && file[i - 1] == 'n'
		&& file[i - 2] == 'p' && file[i - 3] == '.' && file[i - 4])
		return (1);
	return (0);
}
