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

	if (stack_a->count == 0)
		return (1);
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
		if (tmp->rank <= pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// 기능: end값보다 더 큰 수가 있는지 확인, 리턴: 더 큰값이 있으면 1 없으면 0
static int 		check_greater_end(t_list *stack, int end)
{
	t_node *tmp;

	tmp = stack->head->next;
	while (tmp != stack->tail)
	{
		if (tmp->rank > end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// 기능: 스택a가 모두 정렬이 될 때까지 반복 수행, 리턴: void
void			sort_stack_a(t_list *stack_a, t_list *stack_b, int start, int end)
{
	int		pivot;
	int		cnt;

	cnt = 0;
	if (start > end)
		return ; 
	pivot = (start + end) / 2; // 랭킹 첫부분과 마지막 합친 것 / 2 pivot값
	printf("pivot %d\n", pivot);
	set_pivot(stack_a, pivot); // 스택에 피봇인 노드 지정
	while (check_remain_pivot(*stack_a, pivot)) // 노드 <= pivot인 값이 하나라도 남아 있는지 확인
	{
		if (stack_a->head->next->rank < pivot)
			pb(stack_a, stack_b);
		else if (stack_a->head->next->rank == pivot)
		{
			pb(stack_a, stack_b);
			if (check_remain_pivot(*stack_a, pivot)) // a에서 b로 넘길 노드가 남아 있다면 피봇은 스택 맨 아래에 잠시 두어 나머지 노드가 넘어오면 다시 맨 위로 올림
				rb(stack_b);
		}
		else
		{
			cnt++;
			ra(stack_a);
		}
	}
	if (stack_b->head->next->rank != pivot)
		rrb(stack_b); // a에서 b로 넘길 노드가 남아 있다면 피봇은 스택 맨 아래에 잠시 두어 나머지 노드가 넘어오면 다시 맨 위로 올림
	while (check_greater_end(stack_a, end) && cnt && cnt--)
		rra(stack_a);
	sort_stack_a(stack_a, stack_b, pivot + 1, end);
}