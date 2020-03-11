#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include "../libft_list/libft_list.h"
#include "../libft/libft.h"
#include <stdio.h> //del

typedef struct s_stack_sizes
{
    int size_a;
    int size_b;
    int digit;
} t_sizes;

typedef struct s_print_style
{
    int steps;
    int status;
    int color;
    int number;
    int file;
} t_print;

typedef struct s_lists
{
    t_list *list_a;
    t_list *list_b;
} t_lists;

/* basic */
int		get_next_line(const int fd, char **line);

t_list *build_tlist(char **strs, int num, int start, t_sizes *list_sizes);
void move_pieces(t_lists lists, t_sizes *sizes, t_print print);
void print_stacks(t_list *list_a, t_list *list_b, t_sizes *sizes);
void check_order(t_lists lists, t_sizes *sizes, int color);

/* operations */
t_list *reverse_a(t_list *list_a, int size, char direction, t_print print);
t_list *reverse_b(t_list *list_b, int size, char direction, t_print print);
void swap(t_list *list, int size, t_print print, char c);
t_list *push_a(t_list *list_a, t_list **list_b, t_print print, t_sizes *sizes);
t_list *push_b(t_list **list_a, t_list *list_b, t_print print, t_sizes *sizes);

/* reset stage & check_valid */
int print_error(int color, int errno);
int set_print(t_print *print, int num, char **strs);
void set_print_def(t_print *print);
int check_str_valid(char **strs, int num, int *start);

#endif