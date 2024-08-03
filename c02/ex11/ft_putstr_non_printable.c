/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:56:29 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/21 13:12:03 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

///////////////////////////////////////////////////////////////////
// func for check if c is printable
int	check_printable(char c)
{
	if (!(c >= ' ' && c <= '~'))
	{
		return (1);
	}
	return (-1);
}

///////////////////////////////////////////////////////////////////
// func for obtain src length
int	len(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

///////////////////////////////////////////////////////////////////
// func for convert unprintable to hex
void	convert_unprintable(char *result, char c)
{
	const char	*data = "0123456789abcdef";

	result[0] = '\\';
	result[1] = data[c / 16];
	result[2] = data[c % 16];
	result[3] = '\0';
}

///////////////////////////////////////////////////////////////////
// Main func
void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex[3];

	i = 0;
	while (str[i] != '\0')
	{
		if ((check_printable(str[i]) == 1))
		{
			convert_unprintable(hex, str[i]);
			write(1, hex, 3);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
/*
int main()
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	return 0;
} */