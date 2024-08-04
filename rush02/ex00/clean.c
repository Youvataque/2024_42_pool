/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:34:28 by yseguin           #+#    #+#             */
/*   Updated: 2024/08/03 17:54:39 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

///////////////////////////////////////////////////////////////////
// clean str malloc
void	clean_str(char *str)
{
	free(str);
}

///////////////////////////////////////////////////////////////////
// clean tab of str malloc
void	clean_str_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

///////////////////////////////////////////////////////////////////
// clean t_dic malloc
void clean_dic(t_dic *dic)
{
    int i = 0;
    while (dic[i].value != NULL)
    {
        free(dic[i].key);
        free(dic[i].value);
        i++;
    }
    free(dic);
}