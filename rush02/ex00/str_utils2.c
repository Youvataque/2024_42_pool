/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:30:56 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/04 23:29:07 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "struct.h"

int		ft_control(char *str);
int		ft_strlen(char *str);

/////////////////////////////////////////////
// func for deplicate str
char	*ft_strdup_key(char *src)
{
	char	*dup;
	char	*end;
	char	*dup_ptr;

	end = src + ft_strlen(src) - 1;
	while (end > src && *end == ' ')
		end--;
	dup = malloc((end - src + 2) * sizeof(char));
	if (!dup)
		return (NULL);
	dup_ptr = dup;
	while (src <= end)
	{
		*dup_ptr++ = *src++;
	}
	*dup_ptr = '\0';
	return (dup);
}

/////////////////////////////////////////////
// func for duplicate value (remove leading spaces)
char	*ft_strdup_value(char *src)
{
	char	*dup;
	char	*dup_ptr;

	while (*src == ' ')
		src++;
	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup_ptr = dup;
	while (*src)
	{
		*dup_ptr++ = *src++;
	}
	*dup_ptr = '\0';
	return (dup);
}

/////////////////////////////////////////////
// skip zero for all number
char	*ft_skip_zero(char *str)
{
	if (ft_strlen(str) == 1)
		return (str);
	while ((*str == '0' || (*str >= 9 && *str <= 13)
			|| *str == 32 || *str == 43) && ft_strlen(str) > 1)
		str++;
	return (str);
}

/////////////////////////////////////////////
// func to check if input is correct
int	ft_check_input(char *str)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 43)
		str++;
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			str++;
		else
			return (0);
	}
	return (1);
}

/////////////////////////////////////////////
// print zero is av is 0 and key_len 1
void	ft_is_zero(char *str, t_dic *tab)
{
	int	j;

	j = 0;
	while (*str != tab[j].key[0] || tab[j].key_len != 1
		|| ft_control(tab[j].key) == 0)
		j++;
	write(1, tab[j].value, ft_strlen(tab[j].value));
	write(1, "\n", 1);
}
