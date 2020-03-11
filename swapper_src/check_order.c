#include "../includes/push_swap.h"

void write_result(int result, int color)
{	
	if (result == 1)
	{
		if (color)
			write(1, "\e[1;32mOK\n\e[0m", 15);
		else
			write(1, "OK\n", 3);	
	}
	else
	{
		if (color)
			write(1, "\e[1;31mKO\n\e[0m", 15);
		else
			write(1, "KO\n", 3);
	}
}

void check_order(t_lists lists, t_sizes *sizes, int color)
{
	int i;
	int prev;
	
	i = 0;
	if (sizes->size_b == 0)
	{
		while (i < sizes->size_a - 1)
		{
		    prev = lists.list_a->num;
		    lists.list_a = lists.list_a->next;
			if (prev > lists.list_a->num)
			{
			    write_result(0, color);
			    return;
			}
			i++;
		}
		if (i == sizes->size_a - 1)
		{
			write_result(1, color);
			return;
		}
	}
	write_result(0, color);
}