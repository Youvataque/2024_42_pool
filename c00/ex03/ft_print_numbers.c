/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:23:15 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/18 12:09:11 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

//////////////////////////////////////////////////////////////////////
// convert func for int to str
char	convert_int_str(int n)
{
	return (48 + n);
}

void	ft_print_numbers(void)
{
	char	to_print;
	int		i;

	i = 0;
	while (i < 10)
	{
		to_print = convert_int_str(i);
		write(1, &to_print, 1);
		i++;
	}
}

/*int main()
{
    ft_print_numbers();
    return 0;
}*/
