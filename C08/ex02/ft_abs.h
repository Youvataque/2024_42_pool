/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seguinyannis <seguinyannis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:08:16 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/31 18:29:55 by seguinyanni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

unsigned int	abs_val(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

# define ABS(x) (abs_val((x)))

#endif