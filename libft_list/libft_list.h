#ifndef LIBFT_LIST_H
#define LIBFT_LIST_H

#include <stdlib.h>

typedef struct s_list
{
    struct s_list *next;
    struct s_list *prev;
    int num;
} t_list;

t_list	*ft_lstnew(int num);
int		ft_lstaddend(t_list **alst, t_list *new);
t_list *ft_lstrmfirst(t_list *list);
void	ft_lstclear(t_list **list);
int ft_lstsize(t_list *list);
int				ft_printf(char *str, ...);

#endif