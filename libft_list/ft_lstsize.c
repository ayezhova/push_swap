#include "libft_list.h"

int ft_lstsize(t_list *list)
{
    t_list *first;
    int count;
    
    count = 0;
    if (!list)
        return count;
    first = list;
    while (list->next != first)
    {
        count++;
        list = list->next;
    }
    return count + 1;
}