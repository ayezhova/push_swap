/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:10:19 by ayezhova          #+#    #+#             */
/*   Updated: 2019/09/18 09:10:46 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
		return (ch - 32);
	else
		return (ch);
}
