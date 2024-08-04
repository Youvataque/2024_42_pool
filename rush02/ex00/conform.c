/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:07:39 by yseguin           #+#    #+#             */
/*   Updated: 2024/08/04 23:30:28 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str);

///////////////////////////////////////////////////////////////////
// function that check if dic contain \n
void	check_n(int *colon_found, char *str)
{
	if (*str == '\n')
	{
		*colon_found = 1;
	}
}

///////////////////////////////////////////////////////////////////
// check integrity of one line of the Map
int	check_patern(char *str)
{
	int		i;
	int		colon_found;

	i = 0;
	colon_found = 0;
	check_n(&colon_found, str);
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == ':')
		{
			if (colon_found)
				return (0);
			colon_found = 1;
		}
		i++;
	}
	if (colon_found == 1)
		return (1);
	return (0);
}

///////////////////////////////////////////////////////////////////
// Check all Map integrity
int	is_conform(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (i < ft_strlen(str) - 1)
	{
		j = i;
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n' && str[i + 1] != '\0')
			i++;
		else
		{
			if (!check_patern(&str[j]))
				return (0);
			return (1);
		}
		if (!check_patern(&str[j]))
			return (0);
	}
	return (1);
}

///////////////////////////////////////////////////////////////////
// check if the id is usable or must be skip
int	ft_control(char *str)
{
	int	i;

	i = 0;
	if (!(str[0] >= '0' && str[0] <= '9'))
		return (0);
	if (ft_strlen(str) == 2)
	{
		if (!(str[0] >= '1' && str[0] <= '9'))
			return (0);
		if (str[0] != '1' && str[1] != '0')
			return (0);
	}
	if (ft_strlen(str) > 2)
	{
		if (str[0] != '1')
			return (0);
		i++;
		while (str[i])
		{
			if (str[i] != '0')
				return (0);
			i++;
		}
	}
	return (1);
}

/////////////////////////////////////////////
// Sometime good guy need to do bad things
void	ft_margoulin(int *len, char **str)
{
	(*str)++;
	(*len)--;
}
