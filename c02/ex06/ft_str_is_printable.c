/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:45:19 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/21 09:41:10 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int		result;
	int		i;

	result = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= ' ' && str[i] <= '~'))
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}
/*
int main()
{
	printf("%d", ft_str_is_printable("sdfghjk"));
	return 0;
} */