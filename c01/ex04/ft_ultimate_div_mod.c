/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:34:59 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/18 13:36:08 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h> 

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		c;
	int		d;

	c = *a;
	d = *b;
	*a = c / d;
	*b = c % d;
}

/*
int main()
{
	int a = 3;
	int b = 2;

	ft_ultimate_div_mod(&a, &b);
	printf("%d , %d", a, b);
	return 0;
} */