/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:37:58 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/25 16:40:46 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	all_size(char **strs, char *sep, int size)
{
	int		i;
	int		j;
	int		sep_i;
	int		result;

	result = 0;
	i = 0;
	sep_i = 0;
	j = 0;
	while (sep[sep_i])
		sep_i++;
	while (i < size)
	{
		while (strs[i][j])
		{
			j++;
			result++;
		}
		if (i != size - 1)
			result += sep_i;
		j = 0;
		i++;
	}
	return (result);
}

void	add_space(char *sep, char *result, int *x_y_i, int len)
{
	int		i;

	i = 0;
	while (sep[i] && x_y_i[2] < len)
	{
		result[x_y_i[2]] = sep[i];
		x_y_i[2]++;
		i++;
	}
}

char	*not_ok(int size)
{
	char	*result;

	if (size <= 0)
	{
		result = malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	return (NULL);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		x_y_i[3];

	if (not_ok(size) != NULL)
		return (not_ok(size));
	result = malloc((all_size(strs, sep, size) + 1) * sizeof(char));
	x_y_i[0] = 0;
	x_y_i[1] = 0;
	x_y_i[2] = 0;
	while (x_y_i[0] < size)
	{
		while (strs[x_y_i[0]][x_y_i[1]])
		{
			result[x_y_i[2]] = strs[x_y_i[0]][x_y_i[1]];
			x_y_i[2]++;
			x_y_i[1]++;
		}
		if (x_y_i[0] < size - 1)
			add_space(sep, result, x_y_i, all_size(strs, sep, size));
		x_y_i[1] = 0;
		x_y_i[0]++;
	}
	result[x_y_i[2]] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main()
{
	char *strs[] = {"coucou", "bonjour"};
	printf("%s", ft_strjoin(2, strs, "_ _ _"));
	return 0;
} */