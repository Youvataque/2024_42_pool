/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:15:02 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/26 10:26:28 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		len;
	int		i;

	i = 0;
	len = max - min;
	if (len <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(len * sizeof(int));
	while (i < len)
	{
		(*range)[i] = (min + i);
		i++;
	}
	return (len);
}
/*
#include <stdio.h>
int main()
{
	int *result;
	int len = ft_ultimate_range(&result, 12, 23);
	for (int x = 0; x < len; x++)
	{
		printf("%d, ", *result);
		result++;
	}
	return 0;
} */