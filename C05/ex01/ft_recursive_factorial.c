/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:54:36 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/24 11:57:02 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int		result;

	if (nb < 0)
	{
		return (0);
	}
	if (nb != 0)
	{
		result = nb * ft_recursive_factorial(nb -1);
	}
	else
	{
		return (1);
	}
	return (result);
}

/*
int main()
{
	printf("%d", ft_recursive_factorial(5));
	return 0;
} */