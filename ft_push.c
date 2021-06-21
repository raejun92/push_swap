#include "ft_push_swap.h"

// 기능: b의 맨 위 1개를 a의 맨 위로 이동, 리턴: void
void			pa(t_list *stack_a, t_list *stack_b)
{
	int		tmp;
	
	if (stack_b->count == 0)
	{
		printf("b는 비어있음");
		exit (0);
	}
	tmp = stack_b->head->next->data;
	remove_node(stack_b);
	add_node2(stack_a, tmp);
	printf("pa\n");
	rst += 1;
}

// 기능: a의 맨 위 1개를 b의 맨 위로 이동, 리턴: void
void			pb(t_list *stack_a, t_list *stack_b)
{
	int		tmp;

	if (stack_a->count == 0)
	{
		printf("a는 비어있음");
		exit (0);
	}
	tmp = stack_a->head->next->data;
	remove_node(stack_a);
	add_node2(stack_b, tmp);
	printf("pb\n");
	rst += 1;
}