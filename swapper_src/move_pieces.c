#include "../includes/push_swap.h"

int count_steps(char *str, t_sizes *sizes)
{
	int num_steps;
	
	num_steps = 0;
	if ((ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "ss") == 0) && sizes->size_a > 1)
		num_steps++;
	if ((ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0) && sizes->size_b > 1)
		num_steps++;
	if ((ft_strcmp(str, "pa") == 0 && sizes->size_b > 0) || (ft_strcmp(str, "pb") == 0 && sizes->size_a > 0))
		num_steps++;
	if ((ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rr") == 0) && sizes->size_a > 0)
		num_steps++;
	if ((ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0) && sizes->size_b > 0)
		num_steps++;
	if ((ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0) && sizes->size_a > 0)
		num_steps++;
	if ((ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0) && sizes->size_b > 0)
		num_steps++;
	return num_steps;
}

t_lists handle_input(char *str, t_lists lists, t_sizes *sizes, t_print print)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "ss") == 0)
		swap(lists.list_a, sizes->size_a, print, 'A');
	if (ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0)
		swap(lists.list_b, sizes->size_b, print, 'B');
	if (ft_strcmp(str, "pa") == 0)
		lists.list_a = push_a(lists.list_a, &lists.list_b, print, sizes);
	if (ft_strcmp(str, "pb") == 0)
		lists.list_b = push_b(&lists.list_a, lists.list_b, print, sizes);
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rr") == 0)
		lists.list_a = reverse_a(lists.list_a, sizes->size_a, 'f', print);
	if (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0)
		lists.list_b = reverse_b(lists.list_b, sizes->size_b, 'f', print);
	if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0)
		lists.list_a = reverse_a(lists.list_a, sizes->size_a, 'r', print);
	if (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0)
		lists.list_b = reverse_b(lists.list_b, sizes->size_b, 'r', print);
	return lists;
}

void print_number_steps(int num_steps)
{
    write(1, "Num Steps: ", 12);
	ft_putnbr(num_steps);
	write(1, "\n", 1);
}

void move_pieces(t_lists lists, t_sizes *sizes, t_print print)
{
	char *str;
	int num_steps;
	
	num_steps = 0;
	while (get_next_line(1, &str))
	{
		if (print.number && print.steps && count_steps(str, sizes) > 0)
		{
		    ft_putnbr(num_steps + 1);
		    write(1, ". ", 2);
		}
		num_steps += count_steps(str, sizes);
		lists = handle_input(str, lists, sizes, print);
		free(str);
		if (print.status == 1)
			print_stacks(lists.list_a, lists.list_b, sizes);
	}
	check_order(lists, sizes, print.color);
	if (print.number)
	    print_number_steps(num_steps);
	if (sizes->size_a > 0)
		ft_lstclear(&lists.list_a);
	if (sizes->size_b > 0)
		ft_lstclear(&lists.list_b);
}