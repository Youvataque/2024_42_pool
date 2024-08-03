/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:39:04 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/24 14:43:40 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int		result;

	result = nb;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	result = result * ft_recursive_power(nb, power - 1);
	return (result);
}

/*
#include <stdio.h>
int main()
{
	printf("%d", ft_recursive_power(2, 4));
	return 0;
} */