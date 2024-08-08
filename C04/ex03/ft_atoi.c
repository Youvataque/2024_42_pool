/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:59:51 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/24 11:38:27 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

////////////////////////////////////////////////////////////
// func for obtain str length
int	len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

////////////////////////////////////////////////////////////
// func to check if char is decimal and get its value
int	char_to_value(char c)
{
	int			i;
	const char	*base = "0123456789";

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
// main func
int	ft_atoi(char *str)
{
	int		result;
	int		sign;
	int		value;

	result = 0;
	sign = 0;
	check_special(&str, &sign);
	while (*str)
	{
		value = char_to_value(*str);
		if (value == -1)
			break ;
		result = result * 10 + value;
		str++;
	}
	if (!(sign % 2 == 0))
	{
		result = -result;
	}
	return (result);
}
/*
int main()
{
    printf("%d\n", ft_atoi("---+2147gjbn-48364"));   
    printf("%d\n", ft_atoi(" -14353"));     
    printf("%d\n", ft_atoi("- 4567"));                   
    return 0;
} */