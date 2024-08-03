/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:41:55 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/21 09:20:24 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int		result;
	int		i;
	char	t;

	result = 1;
	i = 0;
	while (str[i] != '\0')
	{
		t = str[i];
		if (!(t >= 'a' && t <= 'z') && !(t >= 'A' && t <= 'Z'))
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
	char *test = "PUTAINMARCHEs1";
	printf("%d\n", ft_str_is_alpha(test));
	return 0;
} */