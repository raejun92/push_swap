#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // 나중에 지움

typedef struct	s_node
{
	struct		s_node	*next;
	struct		s_node	*prev;
	int			pivot;
	int			rank;
	int			sort;
	int			data;
}				t_node;

typedef struct	s_list
{
	t_node		*head;
	t_node		*tail;
	int			count;
}				t_list;

int				rst;

/* main.c */
void			enroll_rank(t_list *stack_a, int *sorted_node);
void			sort_first_a(t_list *stack_a, t_list *stack_b, int *sorted_node);
void			set_pivot(t_list *stack_a, int pivot);

/* ft_utils.c */
int				ft_atoi(const char *str);
int				check_ascending(t_list stack_a);
void			set_sort(t_list *stack);
int				out_of_alignment(t_list *stack);

/* ft_utils2.c */
void			error_msg();

/* ft_linked_list.c */
t_node			*new_node(int data);
void			init_list(t_list *list);
void			add_node(t_list *list, int data);
void			view_node(t_list *list);
void			remove_node(t_list *list);

/* ft_switch.c */
void            sa(t_list *stack);
void            sb(t_list *stack);
void            ss(t_list *stack_a, t_list *stack_b);

/* ft_push.c */
void			pa(t_list *stack_a, t_list *stack_b);
void			pb(t_list *stack_a, t_list *stack_b);

/* ft_rotate.c */
void			ra(t_list *stack);
void			rb(t_list *stack);
void			rr(t_list *stack_a, t_list *stack_b);

/* ft_reverse_rotate.c */
void			rra(t_list *stack);
void			rrb(t_list *stack);
void			rrr(t_list *stack_a, t_list *stack_b);

/* ft_check_input.c */
void			check_input(char *param, t_list *stack_a);

/* ft_make_sorted_array.c */
void			make_sorted_array(t_list stack_a, int *sorted_node);

/* ft_simple_sort.c */
void			sort_two_node_a(t_list *stack);
void			sort_three_node_a(t_list *stack);
void			sort_five_node_a(t_list *stack_a, t_list *stack_b, int *sorted_node);

/* ft_stack_a.c */
int				stack_a_max(t_list stack);
int				stack_a_min(t_list stack);
void			sort_stack_a(t_list *stack_a, t_list *stack_b, int start, int end);

/* ft_sort.c */
void			sort_three(t_list *stack);

#endif