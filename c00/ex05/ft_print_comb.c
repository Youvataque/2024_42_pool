/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:38:51 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/18 12:26:05 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

//////////////////////////////////////////////////////////////////////
// convert func for int to str
char	convert_int_str(int n)
{
	return (48 + n);
}

//////////////////////////////////////////////////////////////////////
// print func
void	print_result(char *val, int i, int j, int x)
{
	write(1, &val[0], 1);
	write(1, &val[1], 1);
	write(1, &val[2], 1);
	if (i == 7 && j == 8 && x == 9)
	{
		return ;
	}
	write(1, ",", 1);
	write(1, " ", 1);
}

//////////////////////////////////////////////////////////////////////
// main func
void	ft_print_comb(void)
{
	int		index[3];
	char	val[3];

	index[0] = 0;
	index[1] = 1;
	index[2] = 2;
	while (index[0] < 10)
	{
		val[0] = convert_int_str(index[0]);
		while (index[1] < 10)
		{
			val[1] = convert_int_str(index[1]);
			while (index[2] < 10)
			{
				val[2] = convert_int_str(index[2]);
				print_result(val, index[0], index[1], index[2]);
				index[2]++;
			}
			index[1]++;
			index[2] = index[1] + 1;
		}
		index[1] = index[0] + 1;
		index[0]++;
	}
}
/*
int main()
{
  ft_print_comb();
  return 0;
} */