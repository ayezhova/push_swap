/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_nosign.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:39:18 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/13 18:10:07 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countdigits_nosign(int n)
{
	int count;
	int sign;

	sign = 0;
	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483647 - 1)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		sign++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count + sign);
}
