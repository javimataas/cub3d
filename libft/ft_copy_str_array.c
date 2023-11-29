/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:49:15 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/11/29 16:51:26 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copy_str_array(char **strs)
{
	char	**res;
	int		i;

	i = 0;
	while (strs[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		res[i] = ft_strdup(strs[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}
