/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:06:36 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/22 16:23:14 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

////////////////////////////////////////////////////////////////
//func for compqre s1 and s2
int	ft_strcmp(char *s1, char*s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{	
		if (s1[i] - s2[i] < 0)
		{	
			return (-1);
		}
		else if (s1[i] - s2[i] > 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
/*
int main()
{	
	printf("%d", ft_strcmp("coucov", "coucou"));
	return 0;
} */
