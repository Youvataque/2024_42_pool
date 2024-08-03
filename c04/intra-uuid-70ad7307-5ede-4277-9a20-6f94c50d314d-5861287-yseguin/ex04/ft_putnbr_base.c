/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:36:39 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/24 11:38:30 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

////////////////////////////////////////////////////////////
// func for str length
int	len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

////////////////////////////////////////////////////////////
// func for know if str contain c at a different index
int	contain(char *str, char c, int j)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && i != j)
			return (1);
		i++;
	}
	return (0);
}

////////////////////////////////////////////////////////////
// func for error
int	error_base(char *base, int len_base)
{
	int		i;

	if (len_base <= 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		if (contain(base, base[i], i))
			return (1);
		i++;
	}
	return (0);
}

////////////////////////////////////////////////////////////
// main func
void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	c;

	base_len = len(base);
	if (error_base(base, base_len))
		return ;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base(-(nbr / base_len), base);
		c = base[-(nbr % base_len)];
		write(1, &c, 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	c = base[nbr % base_len];
	write(1, &c, 1);
}

/*
int main()
{
	ft_putnbr_base(-2147483648, "0123456789abcdef-");
	return 0;
} */
