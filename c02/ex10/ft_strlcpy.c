/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:45:45 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/21 13:41:17 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

///////////////////////////////////////////////////////////////////
// Func for obtain src length (like in c01 )
unsigned int	len(char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

///////////////////////////////////////////////////////////////////
// Main func
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = len(src);
	if (size == 0)
	{
		return (l);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dest[i] = '\0';
	}
	return (l);
}

/*
int main()
{
	char *src = "couc";
	char dest[8];
	ft_strlcpy(dest, src, 8);
	printf("%s", dest);
	if (dest[7] == '\0') {
		printf("%d", 42);
	}
	return 0;
} */
