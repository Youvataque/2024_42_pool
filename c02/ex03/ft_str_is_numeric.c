/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:16:52 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/21 09:25:19 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int		i;
	int		result;

	result = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}

/*
int     main()
{
    printf("%d", ft_str_is_numeric("0456897980t"));
    return 0;
} */