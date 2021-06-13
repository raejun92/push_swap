#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct	s_node
{
	struct		s_node *next;
	struct		s_node *prev;
	int			data;
}				t_node;

typedef struct	s_list
{
	t_node		*head;
	t_node		*tail;
	int			count;
}				t_list;

/* ft_utils.c */
int				ft_isdigit(int c);
int				ft_atoi(const char *str);

/* ft_linked_list.c */
t_node			*new_node(int data);
void			init_list(t_list *list);
void			add_node(t_list *list, int data);
void			view_node(t_list *list);
void			remove_node(t_list *list, t_node *cur);

/* ft_switch.c */
void            sa_sb(t_list *stack);
void            ss(t_list *stack_a, t_list *stack_b);

/* ft_push.c */
void			pa(t_list *stack_a, t_list *stack_b);
void			pb(t_list *stack_a, t_list *stack_b);

/* ft_rotate.c */
void			ra_rb(t_list *stack);
void			rr(t_list *stack_a, t_list *stack_b);

/* ft_reverse_rotate.c */
void			rra_rrb(t_list *stack);
void			rrr(t_list *stack_a, t_list *stack_b);

#endif