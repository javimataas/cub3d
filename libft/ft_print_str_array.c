/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:21:43 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/28 17:05:34 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_str_array(char **array)
{
	int		i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		ft_printf("%s", array[i]);
		i++;
	}
}
