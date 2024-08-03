/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:25:38 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/28 17:11:29 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

////////////////////////////////////////////////////////////
// func to check if char is in base and get its value
int	char_to_value(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

////////////////////////////////////////////////////////////
// func to check if a base is valid
int	error_base(char *base, int len_base)
{
	int		i;
	int		j;

	if (len_base <= 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

////////////////////////////////////////////////////////////
// func to check if the selected char is a controller or -, +
void	check_special(char **str, int *sign)
{
	while ((**str == ' ' || (**str >= 9 && **str <= 13)) && *sign == 0)
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign += 1;
		(*str)++;
	}
}

////////////////////////////////////////////////////////////
// atoi base func : used for convert base to int 
int	ft_atoi_base(char *str, char *base)
{
	int		result;
	int		sign;
	int		base_len;
	int		value;

	base_len = 0;
	while (base[base_len])
		base_len++;
	result = 0;
	sign = 0;
	check_special(&str, &sign);
	while (*str)
	{
		value = char_to_value(*str, base);
		if (value == -1)
			break ;
		result = result * base_len + value;
		str++;
	}
	if (!(sign % 2 == 0))
		result = -result;
	return (result);
}

////////////////////////////////////////////////////////////
// func for obtain str len
int	len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
