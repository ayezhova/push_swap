NAME = checker

SWAP_SRC_C = swapper_src/build_tlist.c swapper_src/check_order.c \
	swapper_src/move_pieces.c swapper_src/operations.c \
	swapper_src/print_stacks.c swapper_src/check_valid.c

SWAP_SRC_O = obj/build_tlist.o obj/check_order.o obj/move_pieces.o \
	obj/operations.o obj/print_stacks.o obj/check_valid.o
	
LIBFT_LIST_O = obj/ft_lstaddend.o obj/ft_lstaddfront.o obj/ft_lstclear.o \
	obj/ft_lstnew.o obj/ft_lstrmfirst.o obj/ft_lstsize.o

all: $(NAME)

$(NAME):
	cd libft && $(MAKE)
	gcc -Wall -Wextra -Werror -c -I includes/push_swap.h GNL/get_next_line.h libft_list/libft_list.h libft_list/*.c $(SWAP_SRC_C) swapper_src/checker_main.c pusher/push_swap_main.c GNL/get_next_line.c
	mkdir obj
	mv *.o obj
	gcc $(SWAP_SRC_O) $(LIBFT_LIST_O) obj/get_next_line.o obj/checker_main.o -o $(NAME) libft/libft.a
	gcc $(SWAP_SRC_O) $(LIBFT_LIST_O) obj/get_next_line.o obj/push_swap_main.o -o push_swap libft/libft.a

clean:
	/bin/rm -rf obj

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f push_swap

re: fclean all

.PHONY : clean fclean
