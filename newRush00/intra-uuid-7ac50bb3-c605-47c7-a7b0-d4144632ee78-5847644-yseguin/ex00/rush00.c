/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibourk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:28:20 by yibourk           #+#    #+#             */
/*   Updated: 2024/07/20 16:28:38 by yibourk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

////////////////////////////////////////////////////////////
// func for check corner and return if the position is a corner or not
int	check_c(int i, int len, int x, int y)
{
	if (i == 1 || i == x || i == len - x + 1 || i == len)
	{
		ft_putchar('o');
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
		ft_putchar('|');
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
		if (check_c(i, len, x, y) == -1)
		{
			if (i <= x || i >= len - x + 1)
			{
				ft_putchar('-');
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
