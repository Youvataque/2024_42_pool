/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:10:34 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/22 16:23:10 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

////////////////////////////////////////////////////////////////
//func for compqre s1 and s2 with n lenth
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
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
	printf("%d", ft_strncmp("coucou", "coucov", 6));
	return 0;
} */
