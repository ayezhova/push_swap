/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:57:43 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/12 12:12:41 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_lstclear(t_list **list)
{
	t_list *link;
	t_list *temp;
	t_list *first;

	link = *list;
	if (link->next != link)
	{
		first = link;
		link = link->next;
		while (link != first)
		{
			temp = link->next;
			free(link);
			link = temp;
		}
	}
	free (link);
}
