/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:34:20 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/24 17:42:35 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int		i;

	i = 2;
	if (nb < 2)
	{
		return (0);
	}
	while (i < nb)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int		result;

	result = nb;
	while (!ft_is_prime(result))
	{
		result++;
	}
	return (result);
}

/*
#include <stdio.h>
int main()
{
	printf("%d", ft_find_next_prime(6));
	return 0;
} */