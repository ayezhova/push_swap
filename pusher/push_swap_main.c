#include "../includes/push_swap.h"

int main(int ar, char **av)
{
	t_sizes list_sizes;
	t_print print;
	t_lists lists;
	int start;
	
	if (ar < 2 || set_print(&print, ar - 1, &av[1]) == 0)
		return print_error(print.color, 1);
	if (check_str_valid(&av[1], ar - 1, &start) == 0)
	    return print_error(print.color, 2);
	lists.list_a = build_tlist(&av[1], ar - 1, start, &list_sizes);
	if (list_sizes.size_a == 0)
	    return print_error(print.color, 1);
	if (print.status == 1)
		print_stacks(lists.list_a, lists.list_b, &list_sizes);
	move_pieces(lists, &list_sizes, print);
}