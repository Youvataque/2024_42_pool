/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:42:27 by yseguin           #+#    #+#             */
/*   Updated: 2024/08/01 17:04:23 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = 0;
	while (src[l])
		l++;
	if (size == 0)
		return (l);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dest[i] = '\0';
	}
	dest[i] = '\0';
	return (l);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	int				size;
	t_stock_str		*result;

	result = malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		size = len(av[i]);
		result[i].str = av[i];
		result[i].copy = malloc(sizeof(char) * (size + 1));
		if (result[i].copy == NULL)
			return (NULL);
		ft_strlcpy(result[i].copy, av[i], size + 1);
		result[i].size = size;
		i++;
	}
	result[i].str = 0;
	return (result);
}
