#include "ft_push_swap.h"

// 기능: 스택a 노드들의 랭킹 등록, 리턴: void
void			enroll_rank(t_list *stack_a, int *sorted_node)
{
	t_node	*tmp;
	int		i;

	i = 0;
	while (stack_a->count > i)
	{
		tmp = stack_a->head->next;
		while (tmp->data != sorted_node[i])
			tmp = tmp->next;
		tmp->rank = i + 1;
		i++;
	}
}

// 기능: 첫번째 a스택의 정렬(노드가 2개 또는 3개, 5개일 때), 리턴: void
void			sort_first_a(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	if (stack_a->count == 2)
		sort_two_node_a(stack_a);
	else if (stack_a->count == 3)
		sort_three_node_a(stack_a);
	else if (stack_a->count == 5)
		sort_five_node_a(stack_a, stack_b, sorted_node);
}

// 기능: 피봇인 노드 1로 설정, 리턴: void
void			set_pivot(t_list *stack_a, int pivot)
{
	t_node *tmp;

	tmp = stack_a->head->next;
	while (tmp != stack_a->tail)
	{
		if (tmp->rank == pivot)
		{
			tmp->pivot = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

// 기능: pivot보다 큰 값이 남아 있는지 확인, 리턴: 남아 있으면 1 아니면 0
int				check_greater_than_pivot(t_list stack, int pivot)
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

// 기능: 정렬이 안 된 노드가 3개 이하일 때 정렬 시킴, 리턴: void
void			check_and_sort(t_list *stack_a)
{
	int	cnt;

	if (check_ascending(*stack_a)) // a가 정렬 되어 있으면 리턴
		return ;
	cnt = out_of_alignment(stack_a); // 정렬 되지 않은 노드의 개수
	if (stack_a->count == 2 || cnt == 2)
		sort_two_node_a(stack_a);
	else if (stack_a->count == 3)
		sort_three_node_a(stack_a);
	if (cnt == 3)
		sort_three(stack_a);
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
	// TODO: ra/rra과정 생략할 수 있을 지 찾기
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

// 기능: 스택을 정렬시키는 알고리즘, 리턴: void
void			algorithm(t_list *stack_a, t_list *stack_b)
{
	if (check_ascending(*stack_a) && stack_b->count == 0) // 스택a가 정렬되어 있고 스택b에 아무것도 없다면 조건 만족
		return ;
	else if (!check_ascending(*stack_a)) // 스택a가 정렬되어 있지 않다면 정렬
		sort_stack_a(stack_a, stack_b, stack_a_min(*stack_a), stack_a_max(*stack_a));
	else if (check_ascending(*stack_a) && stack_b->count != 0) // 스택a가 정렬되어 있고 스택b에 노드가 존재한다면 b정렬
		sort_stack_b(stack_a, stack_b, stack_b_max_pivot(*stack_b), stack_b_max(*stack_b));
	check_and_sort(stack_a);
	if (check_ascending(*stack_a))
		set_sort(stack_a);
	algorithm(stack_a, stack_b);
}

int				main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	int		*sorted_node;

	rst = 0;
	if (argc < 3)
		return (0);
	init_list(&stack_a);
	init_list(&stack_b);
	sorted_node = (int *)malloc(sizeof(int) * (argc - 1));
	while (*(++argv)) // ./a.out 이후 검사
		check_input(*argv, &stack_a);
	make_sorted_array(stack_a, sorted_node);
	enroll_rank(&stack_a, sorted_node);
	if (argc <= 4 || argc == 6)
		sort_first_a(&stack_a, &stack_b, sorted_node);
	else
		algorithm(&stack_a, &stack_b);

	// printf("\n");
	// printf("A\n");
	// view_node(&stack_a);
	// printf("\n");
	// printf("B\n");
	// view_node(&stack_b);
	
	
	// printf("\n rst: %d\n", rst);
	free(sorted_node);
	return (0);
}