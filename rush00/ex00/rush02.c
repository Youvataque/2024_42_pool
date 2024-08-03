/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:17:09 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/20 14:41:02 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

////////////////////////////////////////////////////////////
// func for check corner and return if the position is a corner or not
int	check_c(int i, int len, int x)
{
	if ((i == 1 || (i == x)))
	{
		ft_putchar('A');
		return (1);
	}
	else if (i == len || (i == len - x + 1) || (i == len && x == 1))
	{
		ft_putchar('C');
		return (1);
	}
	else
	{
		return (-1);
	}
}

////////////////////////////////////////////////////////////
// func for check position in body and apply border char or espace
void	check_b(int i, int length)
{
	if (i % length == 0 || (i - 1) % length == 0)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

////////////////////////////////////////////////////////////
// main func which control check_c and check_b for the asked result
void	rush(int x, int y)
{
	int		len;
	int		i;

	i = 1;
	len = x * y;
	if (x < 0 || y < 0)
		return ;
	while (i <= len)
	{
		if (check_c(i, len, x) == -1)
		{
			if (i <= x || i >= len - x + 1)
			{
				ft_putchar('B');
			}
			else
			{
				check_b(i, x);
			}
		}
		if (i % x == 0)
			ft_putchar('\n');
		i++;
	}
}
