#include "../includes/push_swap.h"

int check_str_valid(char **strs, int num, int *start)
{
	int i;
	int j;
	int set;
	
	set = 0;
	i = 0;
	while(i < num)
	{
		j = 0;
		while (i < num && strs[i][0] == '-')
			i++;
		if (set == 0)
		{
			(*start) = i;
			set++;
		}
		while (i < num && strs[i][j])
		{
			if (!(strs[i][j] >= '0' && strs[i][j] <= '9') && strs[i][j] != ' ')
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

void set_print_def(t_print *print)
{
	print->steps = 0;
	print->status = 0;
	print->color = 0;
	print->number = 0;
	print->file = 0;
}

int set_print(t_print *print, int num, char **strs)
{
	int i;
	int j;
	
	i = -1;
	set_print_def(print);
	while (++i < num)
	{
		j = -1;
		while(strs[i][++j])
		{
			if (j == 0 && strs[i][j] != '-')
				break;
			if (j > 0 && !(strs[i][j] == 's' || strs[i][j] == 'v' || strs[i][j] == 'c' || strs[i][j] == 'n'))
				return 0;
			if (j > 0 && strs[i][j] == 's')
				print->steps = 1;
			if (j > 0 && strs[i][j] == 'v')
				print->status = 1;
			if (j > 0 && strs[i][j] == 'c')
				print->color = 1;
			if (j > 0 && strs[i][j] == 'n')
				print->number = 1;
			if (j > 0 && strs[i][j] == 'f')
			    print->file = 1;
		}
	}
	return 1;
}

int print_error(int color, int errno)
{
    if (errno == 1)
    {
        if (color)
            write(1, "\e[1;31mUsage: ./push_swap -svcn [arg]\n\e[0m", 44);
        else
            write(1, "Usage: ./push_swap -svcn [arg]\n", 33);
        return 1;
    }
    if (errno == 2)
    {
    	if (color)
			write(1, "\e[1;31mError with arguments.\n\e[0m", 34);
		else
			write(1, "Error with arguments.\n", 23);
		return 2;
    }
    return 0;
}