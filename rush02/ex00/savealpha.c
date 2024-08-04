/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savealpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:51:38 by chdonnat          #+#    #+#             */
/*   Updated: 2024/08/04 17:26:39 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

#include <unistd.h>

int		ft_strlen(char *str);
int		ft_control(char *str);
void	ft_is_zero(char *str, t_dic *tab);

///////////////////////////////////////////////////////////////////
// print unit followed by hundred
void	ft_is_hundred(char *str, t_dic *tab)
{
	int	j;

	j = 0;
	while (*str != tab[j].key[0] || ft_control(tab[j].key) == 0)
		j++;
	if (*str >= '1' && *str <= '9')
	{
		write(1, tab[j].value, ft_strlen(tab[j].value));
		write(1, " ", 1);
	}
	j = 0;
	if (*str != '0')
	{
		while (tab[j].key_len != 3 || ft_control(tab[j].key) == 0)
			j++;
		write(1, tab[j].value, ft_strlen(tab[j].value));
		write(1, " ", 1);
	}
}

///////////////////////////////////////////////////////////////////
// print ten and check for value between 10 - 90
void	ft_is_ten(char *str, t_dic *tab)
{
	int	j;

	if (*str >= '2' && *str <= '9')
	{
		j = 0;
		while (*str != tab[j].key[0] || tab[j].key_len != 2
			|| ft_control(tab[j].key) == 0)
			j++;
		write(1, tab[j].value, ft_strlen(tab[j].value));
		write(1, " ", 1);
	}
	if (*str == '1')
	{
		j = 0;
		str++;
		while (*str != tab[j].key[1] || tab[j].key_len != 2
			|| ft_control(tab[j].key) == 0)
			j++;
		write(1, tab[j].value, ft_strlen(tab[j].value));
		write(1, " ", 1);
		str--;
	}
}

///////////////////////////////////////////////////////////////////
// print number between 1 and 9
void	ft_is_unit(char *str, t_dic *tab)
{
	int	j;

	j = 0;
	if (*str >= '1' && *str <= '9')
	{
		while (*str != tab[j].key[0] || tab[j].key_len != 1
			|| ft_control(tab[j].key) == 0)
			j++;
		write(1, tab[j].value, ft_strlen(tab[j].value));
		write(1, " ", 1);
	}
}

///////////////////////////////////////////////////////////////////
// print big unit using dic val and key_len
void	ft_is_big(char *str, t_dic *tab, int len)
{
	int	j;

	j = 0;
	if (*str == '0' && str[-1] == '0' && str[-2] == '0')
		return ;
	while (len != tab[j].key_len || ft_control(tab[j].key) == 0)
		j++;
	write(1, tab[j].value, ft_strlen(tab[j].value));
	write(1, " ", 1);
}

///////////////////////////////////////////////////////////////////
// print number using ft_func. Slice 3 by 3 and print big unit between
void	ft_print(char *str, t_dic *tab)
{
	int		len;

	len = ft_strlen(str);
	if (*str == '0' && len == 1)
	{
		ft_is_zero(str, tab);
		return ;
	}
	while (len > 1)
	{
		if (len % 3 == 0)
			ft_is_hundred(str, tab);
		if (len % 3 == 2)
			ft_is_ten(str, tab);
		if (len % 3 == 1)
		{		
			if (str[-1] != '1')
				ft_is_unit(str, tab);
			ft_is_big(str, tab, len);
		}
		str++;
		len--;
	}
	ft_is_unit(str, tab);
	write(1, "\n", 1);
}
