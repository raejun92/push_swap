#ifndef PUSH_SWAP_H
# define PSUH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_node
{
	struct		s_node *next;
	struct		s_node *prev;
	int			data;
}				t_node;

typedef struct	s_stack
{
	t_node		*head;
	t_node		*cur;
	int			number;
}				t_stack;

int				ft_isgidit(int c);
int				ft_atoi(const char *str);
#endif