/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:49:15 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/28 17:09:13 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		error_base(char *base, int len_base);
int		len(char *str);

void	ft_putnbr_base_rec(int *nbr_bl, char *base, char *result, int *index)
{
	int		quotient;
	int		remainder;

	if (nbr_bl[0] <= -nbr_bl[1] || nbr_bl[0] >= nbr_bl[1])
	{
		quotient = nbr_bl[0] / nbr_bl[1];
		remainder = nbr_bl[0] % nbr_bl[1];
		nbr_bl[0] = quotient;
		ft_putnbr_base_rec(nbr_bl, base, result, index);
		if (remainder < 0)
			result[(*index)++] = base[-remainder];
		else
			result[(*index)++] = base[remainder];
	}
	else
	{
		if (nbr_bl[0] < 0)
			result[(*index)++] = base[-nbr_bl[0]];
		else
			result[(*index)++] = base[nbr_bl[0]];
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	*result;
	int		index;
	int		t_tab[2];

	base_len = 0;
	index = 0;
	while (base[base_len])
		base_len++;
	result = (char *)malloc(34 * sizeof(char));
	if (!result)
		return ("error");
	if (nbr < 0)
		result[index++] = '-';
	t_tab[0] = nbr;
	t_tab[1] = base_len;
	ft_putnbr_base_rec(t_tab, base, result, &index);
	result[index] = '\0';
	return (result);
}

////////////////////////////////////////////////////////////
// func to check if char is in base and get its value
int	base_to_dec(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		deci_result;

	if (error_base(base_from, len(base_from)))
		return (0);
	if (error_base(base_to, len(base_to)))
		return (0);
	deci_result = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(deci_result, base_to));
}

/*
int	main(void)
{
	printf("%s", ft_convert_base("2D1", "0123456789ABCDEF", "01"));
	return (0);
} */
