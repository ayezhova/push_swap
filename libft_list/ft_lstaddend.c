/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:37:44 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/10 20:13:30 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

int		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (alst != NULL && new != NULL)
	{
		new->next = temp;
		temp->prev = new;
		while (temp->next != *alst)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->prev = temp;
		return (1);
	}
	return (0);
}
