/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sort_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:06:38 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/18 15:11:00 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{	
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = i + 1;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

/*
int main()
{
	int tab[5] = {4, -5, 1, 3, 2};
	ft_sort_int_tab(tab, 5);
	int i = 0;
	while (i < 5)
	{
		printf("%d", tab[i]);
		i++;
	}
	return 0;
} */