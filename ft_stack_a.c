#include "ft_push_swap.h"

// 기능: 스택이 오름차순 정렬되어 있는지 확인, 리턴: 정렬되어 있으면 1 아니면 0
static int		check_ascending(t_list stack_a)
{
	int i;

	i = 0;
	while (i < stack_a.count - 1)
	{
		if (stack_a.head->next->data > stack_a.head->next->next->data)
			return (0);
		stack_a.head = stack_a.head->next;
		i++;
	}
	return (1);
}

// 기능: 스택a가 정렬되어 있다면 정렬되어 있는 노드 체크(1), 리턴: 정렬되어 체크 1, 아니면 0
int				check_stack_a(t_list *stack_a)
{
	t_node	*tmp;
	int		i;

	if (!(check_ascending(*stack_a)))
		return (0);
	tmp = stack_a->head->next;
	i = 0;
	while (i < stack_a->count - 1)
	{
		tmp->check = 1;
		tmp = tmp->next;
		i++;
	}
	return (1);
}

// 기능: pivot보다 작은 값이 남아 있는지 확인, 리턴: 남아 있다면 1 아니면 0
static int		check_remain_pivot(t_list stack, int pivot)
{
	t_node *tmp;

	tmp = stack.head->next;
	while(tmp != stack.tail)
	{
		if (tmp->data <= pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// 기능: 스택a가 모두 정렬이 될 때까지 반복 수행, 리턴: void
void			sort_stack_a(t_list *stack_a, t_list *stack_b, int start, int end)
{
	int		pivot;

	if (start > end)
		return ; 
	pivot = (start + end) / 2;
	set_pivot(stack_a, pivot); // 스택에 피봇인 노드 지정
	while (check_remain_pivot(*stack_a, pivot)) // 노드 <= pivot인 값이 하나라도 남아 있는지 확인
	{
		if (stack_a->head->next->data < pivot)
			pb(stack_a, stack_b);
		else if (stack_a->head->next->data == pivot)
		{
			pb(stack_a, stack_b);
			if (check_remain_pivot(*stack_a, pivot)) // a에서 b로 넘길 노드가 남아 있다면 피봇은 스택 맨 아래에 잠시 두어 나머지 노드가 넘어오면 다시 맨 위로 올림
				rb(stack_b);
		}
		else
			ra(stack_a);
	}
	if (stack_b->head->next->data != pivot)
		rrb(stack_b); // a에서 b로 넘길 노드가 남아 있다면 피봇은 스택 맨 아래에 잠시 두어 나머지 노드가 넘어오면 다시 맨 위로 올림
	sort_stack_a(stack_a, stack_b, pivot + 1, end);
}