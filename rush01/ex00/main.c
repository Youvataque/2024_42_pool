/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:22:52 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/28 12:25:22 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);
int		**char_to_tab(char *str);
char	ft_check_str(char *str);
char	check(int **grid, int **index);
int		***create_all(void);

////////////////////////////////////////////////////////////////////////////
// func for print select tab
void	ft_show(int **tab)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

////////////////////////////////////////////////////////////////////////////
// func for clean after use a malloc int*** tab
void	clean_all_tab(int ***all_tab)
{
	int		j;
	int		k;

	j = 0;
	while (all_tab[j] != NULL)
	{
		k = 0;
		while (all_tab[j][k] != NULL)
		{
			free(all_tab[j][k]);
			k++;
		}
		free(all_tab[j]);
		j++;
	}
	free(all_tab);
}

////////////////////////////////////////////////////////////////////////////
// main func that call str checker, str convert to tab and 
int	main(int argc, char *argv[])
{
	int		**index;
	int		***all_tab;
	int		i;

	i = 0;
	if (argc != 2 || !ft_check_str(argv[1]))
	{
		ft_putstr("Erreur, veuillez saisir 16 numeros compris entre 1 et 4 inclus !");
		return (-1);
	}
	index = char_to_tab(argv[1]);
	if (index == NULL)
		return (-1);
	all_tab = create_all();
	while (all_tab[i] != NULL)
	{
		if (check(all_tab[i], index))
		{
			ft_show(all_tab[i]);
		}
		i++;
	}
	clean_all_tab(all_tab);
	return (0);
}
