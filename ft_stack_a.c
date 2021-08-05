#include "ft_push_swap.h"

// 기능: pivot보다 작은 값이 남아 있는지 확인, 리턴: 남아 있으면 1 아니면 0
static int		check_less_than_pivot(t_list stack, int pivot)
{
	t_node *tmp;

	tmp = stack.head->next;
	while (tmp != stack.tail)
	{
		if (tmp->rank <= pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// 기능: a에서 정렬되지 않은 것 중 가장 큰 랭킹 리턴, 리턴: a에서 정렬되지 않은 것 중 가장 큰 랭킹
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

// 기능: a에서 정렬 안 된 것 중 가장 작은 랭킹 리턴, 리턴: a에서 정렬 안 된 것 중 가장 작은 랭킹
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

static void		sort_stack_a2(t_list *stack_a, t_list *stack_b, int cnt, int pivot)
{

	if (stack_b->head->next->rank != pivot)
		rrb(stack_b);
	while (cnt && cnt--)
		rrb(stack_a);
}

// 기능: 정렬되지 않은 노드 중 제일 큰 값과 작은 값 사이의 피봇을 구해서 피봇보다 작은 값은 b로 보냄, 리턴: void
void			sort_stack_a(t_list *stack_a, t_list *stack_b, int start, int end)
{
	// TODO: 맨처음 피봇이 먼저 움직일 때 문제 발생
	int		pivot;
	int		cnt;

	cnt = 0;
	if (start > end)
		return ;
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
		{
			cnt++;
			ra(stack_a);
		}
	}
	sort_stack_a2(stack_a, stack_b, cnt, pivot);
}