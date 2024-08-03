/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:50:02 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/22 11:27:25 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

////////////////////////////////////////////////////////////////
// func for obain dest len (with special condition)
unsigned int	dest_len_c(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && i < size)
	{
		i++;
	}
	return (i);
}

////////////////////////////////////////////////////////////////
// func for obtain src_len (a classic len)
unsigned int	src_len_c(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

////////////////////////////////////////////////////////////////
// main func
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	i = 0;
	src_len = src_len_c(src);
	dest_len = dest_len_c(dest, size);
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	while (src[i] != '\0' && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
/*
int main()
{
    char *src  = "world";
    char dest[11] = "hello ";
    char *src2  = "world";
    char dest2[11] = "hello ";
    printf("%d\n", ft_strlcat(dest, src, 11));
    printf("%d", strlcat(dest2, src2, 11));
    return 0;
} */
