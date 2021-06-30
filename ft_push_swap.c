#include "ft_push_swap.h"

// 기능: 정렬된 노드 개수 확인, 리턴: 정렬된 노드 개수
int				 check_num(t_list *stack)
{
	t_node *tmp;
	int check_num;

	check_num = 0;
	tmp = stack->head->next;
	while (tmp != stack->tail)
	{
		if (tmp->check == 1)
			check_num++;
		tmp = tmp->next;
	}
	return (check_num);
}

// 기능: 피봇 설정, 리턴: void
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

static void		first_sort_a(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	if (stack_a->count == 3) // 스택a에 초기 3개 노드 정렬
		sort_three_node_a(stack_a);
	else if (stack_a->count == 2) // 스택a에 초기 2개 노드 정렬
		sort_two_node_a(stack_a);
	else if (stack_a->count == 5)  // 스택a에 초기 5개 노드 정렬
		sort_five_node_a(stack_a, stack_b, sorted_node);
}

// 기능: 최솟값의 노드를 찾음, 리턴: 최솟값 노드
static int		find_min_data(t_list stack)
{
	int		min;
	t_node	*tmp;

	tmp = stack.head->next;
	min = stack.head->next->data;
	while (tmp != stack.tail)
	{
		if (min > tmp->data)
			min = tmp->rank;
		tmp = tmp->next;
	}
	return (min);
}

static int		find_min_pivot(t_list stack)
{
	int		p_min;
	t_node	*tmp;

	tmp = stack.head->next;
	p_min = 2147483647;
	while (tmp != stack.tail)
	{
		if (tmp->pivot && p_min > tmp->data)
			p_min = tmp->rank;
		tmp = tmp->next;
	}
	return (p_min);
}

// 기능: pivot보다 큰 값이 남아 있는지 확인, 리턴: 남아 있다면 1 아니면 0
static int		check_remain_pivot(t_list stack, int pivot)
{
	t_node *tmp;

	tmp = stack.head->next;
	while(tmp != stack.tail)
	{
		if (tmp->rank >= pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// 기능: 스택b가 모두 정렬 될 때까지 반복 수행, 리턴: void
void			sort_stack_b(t_list *stack_a, t_list *stack_b, int start, int end)
{
	int pivot;
	int cnt;

	cnt = 0;
	if (start > end)
		return ;
	pivot = (start + end) / 2;
	set_pivot(stack_b, pivot);
	while (check_remain_pivot(*stack_b, pivot))
	{
		if (stack_b->head->next->rank > pivot)
			pa(stack_a, stack_b);
		else if (stack_b->head->next->rank == pivot)
		{
			pa(stack_a, stack_b);
			if (check_remain_pivot(*stack_b, pivot))
				ra(stack_a);
		}
		else
		{
			cnt++;
			rb(stack_b);
		}
	}
	if (stack_a->head->next->rank != pivot)
		rra(stack_a);
	while (cnt && cnt--)
		rrb(stack_b);
	sort_stack_b(stack_a, stack_b, start, pivot - 1);
}

// 기능: 노드 중 가장 큰 수를 출력, 리턴: int(노드중 가장 큰 수)
static int		find_max_data(t_list stack)
{
	int		max;
	t_node	*tmp;

	tmp = stack.head->next;
	max = stack.head->next->data;
	while (tmp != stack.tail)
	{
		if (max < tmp->data)
			max = tmp->rank;
		tmp = tmp->next;
	}
	return (max);
}

// 기능: 스택의 피봇중 가장 큰 랭킹을 찾음, 리턴: 가장 큰 랭킹 값
static int		find_max_pivot(t_list stack)
{
	int		p_max;
	t_node	*tmp;

	tmp = stack.head->next;
	p_max = 0;
	while (tmp != stack.tail)
	{
		if (tmp->pivot && p_max < tmp->rank)
			p_max = tmp->rank;
		tmp = tmp->next;
	}
	if (p_max == 0)
		p_max = find_min_data(stack);
	return (p_max);
}

// 기능: 스택을 정렬하기 위한 알고리즘, 리턴: void
void			algorithm(t_list *stack_a, t_list *stack_b)
{
	if (check_stack_a(stack_a) && (stack_b->count == 0)) // 스택a가 정렬되어 있고 스택b가 비어 있다면 리턴
		return ;
	else if (!check_stack_a(stack_a))
		sort_stack_a(stack_a, stack_b, find_min_data(*stack_a), find_min_pivot(*stack_a));
	else if (check_stack_a(stack_a))
	{
		printf("start: %d, end: %d\n", find_max_pivot(*stack_b), find_max_data(*stack_b));
		sort_stack_b(stack_a, stack_b, find_max_pivot(*stack_b), find_max_data(*stack_b));
	}
	// algorithm(stack_a, stack_b);
}

// 기능: 스택a에서 처음 정렬이 이루어지기까지 수행, 리턴: void
void			set_algorithm(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	if (check_stack_a(stack_a))
		return ;
	else if (!check_stack_a(stack_a))
		sort_stack_a(stack_a, stack_b, 1, stack_a->count); // 처음에 start는 제일 작은 노드, end는 제일 큰 노드
}

// 기능: 스택a의 노드를 랭킹 등록, 리턴: void
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
	while (*(++argv))
		check_input(*argv, &stack_a);
	make_sorted_array(stack_a, sorted_node);
	enroll_rank(&stack_a, sorted_node);
	if (argc <= 4 || argc == 6)
		first_sort_a(&stack_a, &stack_b, sorted_node);
	set_algorithm(&stack_a, &stack_b, sorted_node);
	algorithm(&stack_a, &stack_b);
	// algorithm(&stack_a, &stack_b);
	
	
	printf("\n A \n");
	view_node(&stack_a);
	printf("\n");
	printf("\n B \n");
	view_node(&stack_b);
	free(sorted_node);
	printf("rst = %d\n", rst);
	return (0);
}
