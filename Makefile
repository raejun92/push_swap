NAME = push_swap

OBJS = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_push_swap.c \
		ft_utils.c \
		ft_linked_list.c \
		ft_switch.c \
		ft_push.c \
		ft_rotate.c \
		ft_reverse_rotate.c \
		ft_check_input.c \
		ft_make_sorted_array.c \
		ft_simple_sort.c \
		ft_utils2.c \
		ft_stack_a.c \
		ft_sort.c \
		ft_stack_b.c \
		ft_algorithm.c

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all