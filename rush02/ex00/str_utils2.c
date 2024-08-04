/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:30:56 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/04 20:16:09 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

int		ft_control(char *str);
int		ft_strlen(char *str);

/////////////////////////////////////////////
// func for deplicate str
char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dup;

	if (src[0] == ' ')
		src++;
	len = ft_strlen(src);
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
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

/////////////////////////////////////////////
// Sometime good guy need to do bad things
void	ft_margoulin(int *len, char **str)
{
	(*str)++;
	(*len)--;
}
