/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:29:19 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/25 16:53:34 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

////////////////////////////////////////////////////////////////
//func for compqre s1 and s2
int	ft_strcmp(char *s1, char*s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] - s2[i] < 0)
		{
			return (-1);
		}
		else if (s1[i] - s2[i] > 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

////////////////////////////////////////////////////////////////
//func for sort with result of comparison (strcmp)
void	sort_tab(char **tab, int len)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

////////////////////////////////////////////////////////////////
// main func
int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	sort_tab(argv, argc);
	while (argv[i] != NULL)
	{
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return (0);
}
