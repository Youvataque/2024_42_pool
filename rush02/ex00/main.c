/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:34:01 by yseguin           #+#    #+#             */
/*   Updated: 2024/08/04 19:24:14 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str, char *charset);
t_dic	*convert_tab(char **str_tab);
char	*file_to_string(const char *file_path);
void	clean_str(char *str);
void	clean_str_tab(char **tab);
void	clean_dic(t_dic *dic);
void	ft_print(char *str, t_dic *tab);
int		is_conform(char *str);
int		ft_check_input(char *str);
int		ft_strlen(char *str);
char	*ft_skip_zero(char *str);

///////////////////////////////////////////////////////////////////
// func to execute for check every error and asign var
int	to_execute(char **av, int ac, char **to_print, char **path)
{
	if (ac <= 2)
	{
		*path = "numbers.dict";
		*to_print = ft_skip_zero(av[1]);
	}
	else if (ac == 3)
	{
		*path = av[1];
		*to_print = av[2];
	}
	else
	{
		write(1, "Error Args \n", 13);
		return (0);
	}
	if (ft_check_input(*to_print) == 0 || ft_strlen(*to_print) > 38)
	{
		write(1, "Error Input \n", 13);
		return (0);
	}
	return (1);
}

///////////////////////////////////////////////////////////////////
// call file_to_string -> ft_split -> convert_tab -> ft_print and run
int	main(int ac, char **av)
{
	char	*path;
	char	*str;
	char	**tab;
	char	*to_print;
	t_dic	*struct_tab;

	to_print = "";
	path = "";
	if (ac == 1)
		return (write(1, "Error Input \n", 13), 0);
	if (!to_execute(av, ac, &to_print, &path))
		return (0);
	str = file_to_string(path);
	if (!is_conform(str))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	tab = ft_split(str, ":\n");
	struct_tab = convert_tab(tab);
	clean_str(str);
	ft_print(to_print, struct_tab);
	clean_dic(struct_tab);
	clean_str_tab(tab);
	return (1);
}
