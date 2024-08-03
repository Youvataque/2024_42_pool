/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:59:46 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/24 14:43:20 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int		i;
	int		result;

	i = 0;
	result = nb;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	while (i < power - 1)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

/*
#include <stdio.h>
int main()
{
	printf("%d", ft_iterative_power(2, 0));
	return 0;
} */