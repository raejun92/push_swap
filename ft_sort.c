#include "ft_push_swap.h"

static void		sort_three2(t_list *stack)
{
	// 3 1 2 ...
	if (stack->head->next->next->next->data > stack->head->next->next->data &&
		stack->head->next->next->next->data < stack->head->next->data)
		{
			sa(stack);
			ra(stack);
			sa(stack);
			rra(stack);
		}
	// 3 2 1 ...
	else if (stack->head->next->next->data > stack->head->next->next->next->data &&
		stack->head->next->next->data < stack->head->next->data)
		{
			sa(stack);
			ra(stack);
			sa(stack);
			rra(stack);
			sa(stack);
		}
}

// 기능: 노드 중(3개 이상) 정렬이 안 된 노드가 3개인 경우 정렬시킴, 리턴: void
void			sort_three(t_list *stack)
{
	if (check_ascending(*stack))
		return ;
	// 1 3 2 ...
	if (stack->head->next->next->next->data > stack->head->next->data &&
		stack->head->next->next->next->data < stack->head->next->next->data)
		{
			ra(stack);
			sa(stack);
			rra(stack);
		}
	//2 1 3 ...
	else if (stack->head->next->data > stack->head->next->next->data &&
		stack->head->next->data < stack->head->next->next->next->data)
		{
			sa(stack);
		}
	// 2 3 1 ...
	else if (stack->head->next->data > stack->head->next->next->next->data &&
		stack->head->next->data < stack->head->next->next->data)
		{
			ra(stack);
			sa(stack);
			rra(stack);
			sa(stack);
		}
	sort_three2(stack);
}