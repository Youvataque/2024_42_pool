/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:31:33 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/22 16:23:20 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

////////////////////////////////////////////////////////////////
//func for obtain len
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
//func for add str to an other str "coucou" + " vous" = "coucou vous"
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		i;
	unsigned int		dest_l;

	dest_l = len(dest);
	i = 0;
	while (src[i] != '\0' && i < nb)
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
	ft_strncat(dest, src, 3);
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