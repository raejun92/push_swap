#include "ft_push_swap.h"

// 기능: pivot보다 큰 값이 남아 있는지 확인, 리턴: 남아 있으면 1 아니면 0
static int		check_greater_than_pivot(t_list stack, int pivot)
{
	t_node *tmp;

	tmp = stack.head->next;
	while (tmp != stack.tail)
	{
		if (tmp->rank >= pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// 기능: b의 노드 중 랭킹이 가장 높은 노드를 구함, 리턴: b에서 가장 큰 랭킹 노드
int				stack_b_max(t_list stack)
{
	t_node	*tmp;
	int		max;
	
	max = -2147483648;
	tmp = stack.head->next;
	while (tmp != stack.tail)
	{
		if (tmp->rank > max)
			max = tmp->rank;
		tmp = tmp->next;
	}
	return (max);
}

// 기능: b의 노드 중 피봇이 가장 큰 값을 리턴, 리턴: b에서 가장 큰 피봇 노드
int				stack_b_max_pivot(t_list stack)
{
	t_node	*tmp;
	int		max_pivot;

	max_pivot = -2147483648;
	tmp = stack.head->next;
	while (tmp != stack.tail)
	{
		if (tmp->pivot == 1 && tmp->rank > max_pivot)
			max_pivot = tmp->rank;
		tmp = tmp->next;
	}
	if (!(max_pivot == -2147483648))
		return (max_pivot);
	// 피봇값이 존재하지 않을 경우 가장 작은 랭킹값을 넣음
	max_pivot = 2147483647;
	tmp = stack.head->next;
	while (tmp != stack.tail)
	{
		if (tmp->rank < max_pivot)
			max_pivot = tmp->rank;
		tmp = tmp->next;
	}
	return (max_pivot);
}

static void		sort_stack_b2(t_list *stack_a, t_list *stack_b, int cnt, int pivot)
{
	if (stack_a->head->next->rank != pivot)
		rra(stack_a);
	while (cnt && cnt--)
	{
		if (stack_b->count == 1)
			break ;
		rrb(stack_b);
	}
}

// 기능: 제일 큰 값과 제일 큰 피봇사이의 피봇을 구해 피봇을 포함하여 큰 값을 a로 넘겨줌, 리턴: void
void			sort_stack_b(t_list *stack_a, t_list *stack_b, int start, int end)
{
	int	pivot;
	int	cnt;  // 피봇 보다 작은 수이면 b의 맨 아래로 보낸 후 피봇 이상인 랭킹을 a로 보낸 후 다시 맨 위쪽으로 올림
	
	cnt = 0;
	if (start > end)
		return ;
	pivot = (start + end) / 2;
	set_pivot(stack_b, pivot);
	while (check_greater_than_pivot(*stack_b, pivot))
	{
		if (stack_b->head->next->rank > pivot)
			pa(stack_a, stack_b);
		else if (stack_b->head->next->rank == pivot)
		{
			pa(stack_a, stack_b);
			if (check_greater_than_pivot(*stack_b, pivot))
				ra(stack_a);
		}
		else
		{
			cnt++;
			rb(stack_b);
		}
	}
	sort_stack_b2(stack_a, stack_b, cnt, pivot);
}