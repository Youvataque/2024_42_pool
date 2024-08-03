/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:46:08 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/21 09:43:18 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

////////////////////////////////////////////////////////
///// func for convert A to -> a
char	convert_low(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

////////////////////////////////////////////////////////
///// func for convert a to -> A
char	convert_up(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

////////////////////////////////////////////////////////
///// func for check if we need conversion and what 
void	check_word(char *str, int i)
{
	char	c;

	c = str[i - 1];
	if (!((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123)))
	{
		str[i] = convert_up(str[i]);
	}
	else
	{
		str[i] = convert_low(str[i]);
	}
}

////////////////////////////////////////////////////////
///// main func 
char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		check_word(str, i);
		i++;
	}
	return (str);
}

/*
int main()
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(str);
	printf("%s", str);
} */