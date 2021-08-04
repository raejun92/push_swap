#include "ft_push_swap.h"

// 기능: a에서 정렬되지 않은 것 중 가장 큰 값 리턴, 리턴: a에서 정렬되지 않은 것 중 가장 큰 값
int				stack_a_max(t_list stack)
{
	t_node	*tmp;
	int		max;

	max = -2147483648;
	tmp = stack.head->next;
	while (tmp != stack.tail)
	{
		if (tmp->sort == 0 && tmp->rank > max)
			max = tmp->rank;
		tmp = tmp->next;
	}
	return (max);
}

// 기능: a에서 정렬 안 된 것 중 가장 작은 값 리턴, 리턴: a에서 정렬 안 된 것 중 가장 작은 값
int				stack_a_min(t_list stack)
{
	t_node	*tmp;
	int		min;

	min = 2147483647;
	tmp = stack.head->next;
	while (tmp != stack.tail)
	{
		if (tmp->sort == 0 && tmp->rank < min)
			min = tmp->rank;
		tmp = tmp->next;
	}
	return (min);
}

// 기능: 피봇을 구해서 피봇보다 작은 값은 b로 보내는 작업 반복, 리턴: void
void			sort_stack_a(t_list *stack_a, t_list *stack_b, int start, int end)
{
	// TODO: 3개 이하일 때 정렬 시키기, 노드가 없을 떄와 있을 때 나누어 정렬
	int		pivot;

	if (start > end)
		return ;
	printf("start: %d \t end: %d\n", start, end);
	pivot = (start + end) / 2;
	set_pivot(stack_a, pivot);
	while (check_less_than_pivot(*stack_a, pivot)) // 노드 <= pivot인 값이 하나라도 남아 있는지 확인
	{
		if (stack_a->head->next->rank < pivot)
			pb(stack_a, stack_b);
		else if (stack_a->head->next->rank == pivot) // a에서 b로 넘길 노드가 남아 있다면 피봇은 스택 맨 아래에 잠시 두어 나머지 노드가 넘어오면 다시 맨 위로 올림
		{
			pb(stack_a, stack_b);
			if (check_less_than_pivot(*stack_a, pivot))
				rb(stack_b);
		}
		else
			ra(stack_a);
	}
	if (stack_b->head->next->rank != pivot)
		rrb(stack_b);
}