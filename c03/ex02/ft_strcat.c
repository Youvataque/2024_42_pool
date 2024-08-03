/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:09:26 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/22 16:23:17 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

////////////////////////////////////////////////////////////////
//func for obtain str len
unsigned int	len(char *str)
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
//main func
char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		dest_l;

	dest_l = len(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = '\0';
	return (dest);
}

/*
int main()
{
	char *src = " vous";
	char dest[12] = "coucou";
	ft_strcat(dest, src);
	int i = 0;
	while(dest[i] != '\0')
	{
		if (dest[i] == '\0') {
			write(1, "NULL", 4);
		} else {
			write(1, &dest[i], 1);
		}
		i++;
	}
} */