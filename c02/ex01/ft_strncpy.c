/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:19:48 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/21 13:38:19 by yseguin          ###   ########.fr       */
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
// Func for select the type of cpy and add \0 on all empty slot on case 3
int	select_way(unsigned int n, unsigned int src_len, char *dest)
{
	unsigned int	i;
	unsigned int	void_len;

	i = 0;
	if (src_len == n)
	{
		return (0);
	}
	else if (src_len < n)
	{
		void_len = n - src_len;
		while (i < void_len)
		{
			dest[n - 1 - i] = '\0';
			i++;
		}
		return (1);
	}
	else
	{
		return (-1);
	}
}

///////////////////////////////////////////////////////////////////
// Main Func
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;
	unsigned int		l;
	int					w;

	i = 0;
	l = len(src);
	w = select_way(n, l, dest);
	while (i < n)
	{
		if (i < l)
		{
			dest[i] = src[i];
		}
		else
		{
			dest[i] = '\0';
		}
		i++;
	}
	return (dest);
}

/*
int main()
{
	char *src = "coucou";
	char dest[8];
	ft_strncpy(dest, src, 8);
	printf("%s", dest);
	return 0;
} */
