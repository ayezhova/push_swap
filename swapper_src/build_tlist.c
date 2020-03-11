#include "../includes/push_swap.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	if (str1[i] != '\0' || str2[i] != '\0')
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	else
		return (0);
}

int skip_ws(char *str, int i)
{
	int j;
	
	j = 0;
	while (str[j + i] != '\0' && (str[i + j] == ' ' || str[i + j] == '\t' ||
			str[i + j] == '\n' || str[i + j] == '\v' || str[i + j] == '\f' ||
			str[i + j] == '\r'))
		j++;
	return j;
}

int		ft_atoi(char *str, int *max)
{
	int i;
	int num;
	int sign;
	int j;

	i = 0;
	num = 0;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	j = skip_ws(str, i);
	i += j;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		num = num * -1;
	(*max) = ft_max((*max), i - j);
	return (num);
}

t_list *build_tlist(char **strs, int num, int start, t_sizes *list_sizes)
{
    t_list *list;
    t_list *temp;
    int first;
    int i;
    int j;
    
    i = start;
    first = 0;
    list_sizes->size_a = 0;
    list_sizes->size_b = 0;
    list_sizes->digit = 0;
    while (i < num)
    {
        j = 0;
        while(strs[i][j])
        {
            if (first == 0)
            {
                list = ft_lstnew(ft_atoi(&strs[i][j], &list_sizes->digit));
                first++;
            }
            else
            {
                temp = ft_lstnew(ft_atoi(&strs[i][j], &list_sizes->digit));
                ft_lstaddend(&list, temp);
            }
            while(strs[i][j] >= '0' && strs[i][j] <= '9')
                j++;
            while (strs[i][j] == ' ')
                j++;
            list_sizes->size_a += 1;
        }
        //list_sizes->size_a += 1;
        i++;
    }
    return list;
}