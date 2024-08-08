/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:00:58 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/08 15:34:57 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	contain(char *charset, char c)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *str, int n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	nb_word(char *str, char *charset)
{
	int		i;
	int		is_word;
	int		nb_word;

	i = 0;
	nb_word = 0;
	is_word = 0;
	while (str[i])
	{
		if (!is_word && !contain(charset, str[i]))
		{
			is_word = 1;
			nb_word++;
		}
		else if (is_word == 1 && contain(charset, str[i]))
			is_word = 0;
		i++;
	}
	return (nb_word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		r_i;
	char	**result;

	i = 0;
	r_i = 0;
	result = malloc(sizeof(char *) * (nb_word(str, charset) + 1));
	while (str[i])
	{
		while (contain(charset, str[i]) && str[i])
			i++;
		j = i;
		while (!contain(charset, str[i]) && str[i])
			i++;
		if (i > j)
		{
			result[r_i] = ft_strdup(&str[j], i - j);
			r_i++;
		}
	}
	result[r_i] = 0;
	return (result);
}
