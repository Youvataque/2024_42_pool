/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:39:58 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/18 12:21:46 by yseguin          ###   ########.fr       */
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
void	print_end(char *val)
{
	write(1, &val[0], 1);
	write(1, &val[1], 1);
	write(1, &val[2], 1);
	write(1, &val[3], 1);
	write(1, &val[4], 1);
	if (val[0] == '9' && val[1] == '8')
	{
		return ;
	}
	write(1, ",", 1);
	write(1, " ", 1);
}

//////////////////////////////////////////////////////////////////////
// truncate func for printing
char	*result_convert(int n, char result[2])
{
	int		nb1;
	int		nb2;

	nb1 = n / 10;
	nb2 = n % 10;
	result[0] = convert_int_str(nb1);
	result[1] = convert_int_str(nb2);
	return (result);
}

//////////////////////////////////////////////////////////////////////
// main func 
void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	result[5];
	char	for_convert[2];

	result[2] = ' ';
	i = 0;
	j = 1;
	while (i <= 99)
	{
		result[0] = result_convert(i, for_convert)[0];
		result[1] = result_convert(i, for_convert)[1];
		while (j <= 99)
		{
			result[3] = result_convert(j, for_convert)[0];
			result[4] = result_convert(j, for_convert)[1];
			print_end(result);
			j++;
		}
		i++;
		j = i + 1;
	}
}
/*
int main()
{
    ft_print_comb2();
    return 0;
} */