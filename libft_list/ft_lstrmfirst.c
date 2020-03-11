#include "libft_list.h"

t_list *ft_lstrmfirst(t_list *list)
{
    t_list *temp;
    
    if (list->next == list)
        ft_lstclear(&list);
    else
    {
        temp = list;
        list = list->next;
        list->prev = temp->prev;
        temp->prev->next = list;
        free(temp);
    }
    return list;
}