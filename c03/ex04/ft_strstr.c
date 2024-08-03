/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:37:53 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/21 18:26:51 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

////////////////////////////////////////////////////////////////
//func for check if str contain to find with first equal index
int	check_c_str(char *str, char *to_find, int i)
{
	int		temp_i;
	int		temp_j;

	temp_i = i;
	temp_j = 0;
	while (to_find[temp_j] != '\0')
	{
		if (str[temp_i] != to_find[temp_j])
		{
			return (-1);
		}
		temp_i++;
		temp_j++;
	}
	return (1);
}

////////////////////////////////////////////////////////////////
// main func
char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (check_c_str(str, to_find, i) == 1)
			{	
				return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
int main()
{
	printf("%s\n", ft_strstr("hello world", ""));
	return 0;
} */