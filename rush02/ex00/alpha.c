/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:26:04 by afroechl          #+#    #+#             */
/*   Updated: 2024/08/03 15:49:12 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>

int	str_len(char *str);

void	ft_print(char *str,t_dic *tab)
{
	int	i;
	int	j;
	int	len; 
		
	len = str_len(str);
	i = 0;

	if (str[i] == '0' && len == 1)
	{
		write(1,tab[0].value, str_len(tab[0].value));
		write(1, "\n", 1);
		return;
	}
	while(str[i] != '\0')
	{
		j = 0;
		while (str[i] == '0' )
		{
			i++;
			len--;
		}
		if (i%3 == 1 && str[i] == '1')
		{
			write(1,tab[str[i+1] - 48 + 10].value, str_len(tab[str[i+1] - 48 + 10].value));
			write(1, " ", 1);
			i = i + 2;
			len = len - 1;
			while (len != tab[j].key_len)
			{
				j++;
			}
			write(1, tab[j].value,str_len(tab[j].value));
			write(1, " ", 1);

			len--;
		}
		j = 0;
		while(str[i] != tab[j].key[0])
			j++;
		write(1,tab[j].value,str_len(tab[j].value));
		write(1, " ", 1);
		while(len != tab[j].key_len)
			j++;
		write(1,tab[j].value,str_len(tab[j].value));
		write(1, " ", 1);
		len--;
		i++;
	}
	write(1, "\n", 1);
}
