/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:09:22 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/25 15:13:17 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		len;
	int		i;
	int		*result;

	i = 0;
	len = max - min;
	if (len <= 0)
	{
		result = NULL;
		return (result);
	}
	result = malloc(len * sizeof(int));
	while (i < len)
	{
		result[i] = (min + i);
		i++;
	}
	return (result);
}
/*
#include <stdio.h>
int main()
{
	int *result = ft_range(12, 23);

	for (int x = 0; x < 11; x++)
	{
		printf("%d, ", *result);
		result++;
	}
	return 0;
} */