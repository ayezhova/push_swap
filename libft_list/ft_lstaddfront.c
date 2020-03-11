#include "libft_list.h"

int		ft_lstaddfront(t_list **alst, t_list *new)
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
