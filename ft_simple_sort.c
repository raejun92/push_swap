#include "ft_push_swap.h"

// 기능: 노드 2개 정렬, 리턴: void
void			sort_two_node_a(t_list *stack)
{
	if (stack->head->next->data > stack->head->next->next->data)
		sa(stack);
}

static void		sort_three_node_a2(t_list *stack)
{
	if (check_ascending(*stack))
		return ;
	// 3 1 2
	if (stack->head->next->next->next->data > stack->head->next->next->data &&
		stack->head->next->next->next->data < stack->head->next->data)
			ra(stack);
	// 3 2 1
	else if (stack->head->next->next->data > stack->head->next->next->next->data &&
		stack->head->next->next->data < stack->head->next->data)
		{
			sa(stack);
			rra(stack);
		}
}

// 기능: 노드가 3개 이하 일 때 3개 노드 정렬, 리턴: void
void			sort_three_node_a(t_list *stack)
{
	if (check_ascending(*stack))
		return ;
	// 1 3 2
	if (stack->head->next->next->next->data > stack->head->next->data &&
		stack->head->next->next->next->data < stack->head->next->next->data)
		{
			sa(stack);
			ra(stack);
		}
	//2 1 3
	else if (stack->head->next->data > stack->head->next->next->data &&
		stack->head->next->data < stack->head->next->next->next->data)
		{
			sa(stack);
		}
	// 2 3 1
	else if (stack->head->next->data > stack->head->next->next->next->data &&
		stack->head->next->data < stack->head->next->next->data)
			rra(stack);
	sort_three_node_a2(stack);	
}

static void		sort_two_node_b(t_list *stack)
{
	if (stack->head->next->data < stack->head->next->next->data)
		sb(stack);
}

// 기능: 노드가 5개 있을 때 정렬, 리턴: void
void			sort_five_node_a(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	int i;
	int mid;
	
	i = 0;
	mid = sorted_node[stack_a->count / 2];
	while (i < 2)
	{
		if (mid > stack_a->head->next->data)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	sort_three_node_a(stack_a);
	sort_two_node_b(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}