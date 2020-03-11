#include "../includes/push_swap.h"

t_list *push_a(t_list *list_a, t_list **list_b, t_print print, t_sizes *sizes)
{
	t_list *temp;
	if (sizes->size_b == 0)
		return list_a;
	if (print.steps && print.color)
		write(1, "\e[0;35mPushing Top Element of B to Top of A\n\n\e[0m", 50);
	if (print.steps && !print.color)
		write(1, "Pushing Top Element of B to Top of A\n\n", 39);
	if (sizes->size_a == 0)
	{
		list_a = ft_lstnew((*list_b)->num);
		sizes->size_a = 1;
	}
	else
	{
		temp = ft_lstnew((*list_b)->num);
		ft_lstaddend(&list_a, temp);
		list_a = list_a->prev;
		sizes->size_a += 1;
	}
	(*list_b) = ft_lstrmfirst(*list_b);
	sizes->size_b -= 1;
	return list_a;
}

t_list *push_b(t_list **list_a, t_list *list_b, t_print print, t_sizes *sizes)
{
	t_list *temp;

	if (sizes->size_a == 0)
		return list_b;
	if (print.steps && print.color)
		write(1, "\e[0;35mPushing Top Element of A to Top of B\n\n\e[0m", 50);
	if (print.steps && !print.color)
		write(1, "Pushing Top Element of A to Top of B\n\n", 39);
	if (sizes->size_b == 0)
	{
		list_b = ft_lstnew((*list_a)->num);
		sizes->size_b = 1;
	}
	else
	{
		temp = ft_lstnew((*list_a)->num);
		ft_lstaddend(&list_b, temp);
		list_b = list_b->prev;
		sizes->size_b += 1;
	}
	(*list_a) = ft_lstrmfirst(*list_a);
	sizes->size_a -= 1;
	return list_b;
}

void swap(t_list *list, int size, t_print print, char c)
{
	int temp;
	
	if (size < 2)
		return ;
	if (print.steps && print.color)
	{
		write(1, "\e[0;32mSwapping First Two Numbers in List \e[0m", 46);
		if (c == 'A')
			write(1, "\e[0;32mA\e[0m\n\n", 15);
		if (c == 'B')
			write(1, "\e[0;32mB\e[0m\n\n", 15);
	}
	if (print.steps && !print.color)
	{
		write(1, "Swapping First Two Numbers in List ", 36);
		if (c == 'A')
			write(1, "A\n\n", 3);
		if (c == 'B')
			write(1, "B\n\n", 3);
	}
	temp = list->num;
	list->num = list->next->num;
	list->next->num = temp;
}

t_list *reverse_a(t_list *list_a, int size, char direction, t_print print)
{
	if (size == 0)
		return list_a;
	if (print.steps && print.color)
	{
		if (direction == 'f')
			write(1, "\e[0;36mRotating Top of List A to Bottom\n\n\e[0m", 46);
		if (direction == 'r')
			write(1, "\e[0;36mRotating Bottom of List A to Top\n\n\e[0m", 46);
	}
	if (print.steps && !print.color)
	{
		if (direction == 'f')
			write(1, "Rotating Top of List A to Bottom\n\n", 35);
		if (direction == 'r')
			write(1, "Rotating Bottom of List A to Top\n\n", 35);
	}
	if (direction == 'f')
		return list_a->next;
	return list_a->prev;
}

t_list *reverse_b(t_list *list_b, int size, char direction, t_print print)
{
	if (size == 0)
		return list_b;
	if (print.steps && print.color)
	{
		if (direction == 'f')
			write(1, "\e[0;36mRotating Top of List B to Bottom\n\n\e[0m", 46);
		if (direction == 'r')
			write(1, "\e[0;36mRotating Bottom of List B to Top\n\n\e[0m", 46);
	}
	if (print.steps && !print.color)
	{
		if (direction == 'f')
			write(1, "Rotating Top of List B to Bottom\n\n", 35);
		if (direction == 'r')
			write(1, "Rotating Bottom of List B to Top\n\n", 35);
	}
	if (direction == 'f')
		return list_b->next;
	return list_b->prev;
}