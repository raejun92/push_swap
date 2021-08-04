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

// 기능: pivot보다 작은 값이 남아 있는지 확인, 리턴: 남아 있으면 1 아니면 0
int				check_less_than_pivot(t_list stack, int pivot)
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

// 기능: 피봇을 구해서 피봇보다 작은 값은 b로 보내는 작업 반복, 리턴: void
void			sort_stack_a(t_list *stack_a, t_list *stack_b, int start, int end)
{
	// TODO: 3개 이하일 때 정렬 시키기, 노드가 없을 떄와 있을 때 나누어 정렬
	int		pivot;

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
			ra(stack_a);
	}
	if (stack_b->head->next->rank != pivot)
		rrb(stack_b);
}

// 기능: a에서 정렬 안 된 것 중 가장 작은 값 리턴, 리턴: a에서 정렬 안 된 것 중 가장 작은 값
static int		stack_a_min(t_list stack)
{
	t_node	*tmp;
	int		min;

	min = 0;
	tmp = stack.head->next;
	while (tmp != stack.tail)
	{
		if (tmp->sort == 0 && tmp->rank < min)
			min = tmp->rank;
		tmp = tmp->next;
	}
	return (min);
}

// 기능: a에서 정렬되지 않은 것 중 가장 큰 값 리턴, 리턴: a에서 정렬되지 않은 것 중 가장 큰 값
static int		stack_a_max(t_list stack)
{
	t_node	*tmp;
	int		max;

	max = 0;
	tmp = stack.head->next;
	while (tmp != stack.tail)
	{
		if (tmp->sort == 0 && tmp->rank > max)
			max = tmp->rank;
		tmp = tmp->next;
	}
	return (max);
}

// 기능: 스택을 정렬시키는 알고리즘, 리턴: void
void			algorithm(t_list *stack_a, t_list *stack_b)
{
	if (check_ascending(*stack_a) && stack_b->count == 0) // 스택a가 정렬되어 있고 스택b에 아무것도 없다면 조건 만족
		return ;
	else if (!check_ascending(*stack_a)) // 스택a가 정렬되어 있지 않다면 정렬
		sort_stack_a(stack_a, stack_b, stack_a_min(*stack_a), stack_a_max(*stack_a));
	// else if (check_ascending(*stack_a) && stack_b->count != 0) // 스택a가 정렬되어 있고 스택b에 노드가 존재한다면 b정렬
		// sort_stack_b();
	if (check_ascending(*stack_a))
		set_sort(stack_a);
	// algorithm(stack_a, stack_b);
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
	algorithm(&stack_a, &stack_b);
	printf("\n");
	view_node(&stack_a);
	printf("\n");
	view_node(&stack_b);

	/* TODO: 흐름
	29 | 18 | 47 | 50 | 19 | 49 | 27 | 502 | 184 | 1293 | 1824 | 1 | 291
	랭킹: 5 | 2 | 6 | 8 | 3 | 7 | 4 | 11 | 9 | 12 | 13 | 1 | 10
	
	값이 아닌 랭킹으로 정렬하자
	피봇은 (가장 큰 랭킹 + 가장 작은 랭킹) / 2로 구한다
	스택a에서 더 이상 pivot > 스택a의 랭킹인 값이 없을 때까지 찾는다
	설정된 피봇값이 스택b를 나누는 기준이 된다
	*/
}