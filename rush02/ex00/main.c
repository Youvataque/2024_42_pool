/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:34:01 by yseguin           #+#    #+#             */
/*   Updated: 2024/08/03 16:59:04 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
t_dic	*convert_tab(char **str_tab);
char	*file_to_string(const char *file_path);
void	clean_str(char *str);
void	clean_str_tab(char **tab);
void clean_dic(t_dic *dic);
void	ft_print(char *str, t_dic *tab);

///////////////////////////////////////////////////////////////////
// call file_to_string -> ft_split -> convert_tab -> ft_print and run
int	main(int ac, char **av)
{
	char	*path;
	char	*str;
	char	**tab;
	char	*to_print;
	t_dic	*struct_tab;
	int		i;

	if (ac <= 2)
	{
		path = "numbers.dict";
		to_print = av[1];
	}
	else
	{
		path = av[1];
		to_print = av[2];
	}
	str = file_to_string(path);
	tab = ft_split(str, ": \n");
	struct_tab = convert_tab(tab);
	clean_str(str);
	ft_print(to_print, struct_tab);
	clean_dic(struct_tab);
	clean_str_tab(tab);
	return (0);
}
