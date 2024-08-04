/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:36:55 by seguinyanni       #+#    #+#             */
/*   Updated: 2024/08/03 17:53:30 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

int		ft_strlen(char *str);
char	*ft_strdup(char *src);

///////////////////////////////////////////////////////////////////
// count size of file_path (in bytes)
int	file_size(const char *file_path)
{
	int		bytes_read;
	int		fd;
	int		total_bytes;
	char	buffer[1];

	total_bytes = 0;
	fd = open(file_path, O_RDONLY);
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		total_bytes += bytes_read;
	}
	if (bytes_read == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (total_bytes);
}

///////////////////////////////////////////////////////////////////
// use open and read for convert dico into str file
char	*file_to_string(const char *file_path)
{
	int		fd;
	char	*file_content;
	int		size;

	size = file_size(file_path);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_content = malloc(size + 1);
	if (file_content == NULL)
	{
		close(fd);
		return (NULL);
	}
	if (read(fd, file_content, size) != size)
	{
		free(file_content);
		close(fd);
		return (NULL);
	}
	file_content[size] = '\0';
	close(fd);
	return (file_content);
}

///////////////////////////////////////////////////////////////////
// convert a tab of str into a tab of strut and add key_len to result
t_dic	*convert_tab(char **str_tab)
{
	t_dic	*result;
	int		index[2];

	index[0] = 0;
	index[1] = 0;
	while (str_tab[index[0]] != NULL)
		index[0]++;
	result = malloc((index[0] / 2 + 1) * sizeof(t_dic));
	index[0] = 0;
	while (str_tab[index[0]] != NULL)
	{
		if (index[0] % 2 != 0)
		{
			result[index[1]].value = ft_strdup(str_tab[index[0]]);
			index[1]++;
		}
		else
		{
			result[index[1]].key = ft_strdup(str_tab[index[0]]);
			result[index[1]].key_len = ft_strlen(str_tab[index[0]]);
		}
		index[0]++;
	}
	result[index[1]].value = NULL;
	return (result);
}
