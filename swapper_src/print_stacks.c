#include "../includes/push_swap.h"

static void print_bottom(int digits)
{
	int printed;
	
	write(1, " ", 1);
	print_char('-', digits);
	print_char(' ', 3);
	print_char('-', digits);
	write(1, "\n", 1);
	printed = digits / 2;
	if (digits % 2 == 1)
	{
		print_char(' ', printed);
		write(1, " a", 2);
		print_char(' ', printed + 3);
		print_char(' ', printed);
		write(1, "b\n", 2);
	}
	else
	{
		print_char(' ', printed);
		write(1, " a", 2);
		print_char(' ', printed + 2);
		print_char(' ', printed);
		write(1, "b\n", 2);
	}
}

void write_list_a(int num, int digits)
{
	int printed;

	write(1, " ", 1);
    ft_putnbr(num);
    printed = ft_countdigits_nosign(num);
    print_char(' ', digits - printed);
}

void print_stacks(t_list *list_a, t_list *list_b, t_sizes *sizes)
{
	int i;
	int max;
	int digits;
	
	max = ft_max(sizes->size_a, sizes->size_b);
	i = max + 1;
	digits = sizes->digit;
	while (--i > 0)
	{
	    if (i <= sizes->size_a)
	    {
	        write_list_a(list_a->num, digits);
	        list_a = list_a->next;
	    }
	    else
			print_char(' ', digits + 1);
	    print_char(' ', 3);
	    if (i <= sizes->size_b)
	    {
	        ft_putnbr(list_b->num);
	        list_b = list_b->next;
	    }
	    write(1, "\n", 1);
	}
	print_bottom(digits);
}