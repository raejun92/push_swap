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

// 기능: 배열의 중간 데이터를 출력, 리턴: 배열 중간의 데이터
int				find_middle_data(int *sorted_node, int len)
{
	int			data;
	static int	s_len;

	s_len += len;
	s_len = s_len - 1;
	data = sorted_node[s_len];
	return (data);
}

// 기능: 가운데 데이터를 기준으로 스택a, b의 값을 나눔, 리턴: void
void			divide_half_a(t_list *stack_a, t_list *stack_b, int middle_data)
{
	int	i;
	int len;
 
	i = 0;
	len = (stack_a->count - check_num(stack_a)) / 2;
	while (len > i)
	{
		// printf("len %d, i %d\n", len, i);
		if (stack_a->head->next->data <= middle_data)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

// 기능: 스택이 정렬되어 있는지 확인, 리턴: 정렬되어 있으면 1 아니면 0
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


// 기능: 피봇 설정, 리턴: void
void			set_pivot(t_list *stack_a, int pivot_data)
{
	t_node *pivot;

	pivot = stack_a->head->next;
	while (pivot != stack_a->tail)
	{
		if (pivot->data == pivot_data)
			pivot->pivot = 1;
		pivot = pivot->next;
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

// 기능: pivot보다 작은 값이 남아 있는지 확인, 리턴: 남아 있다면 1 아니면 0
int				 check_remain_pivot(t_list stack, int pivot)
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
		{
			pb(stack_a, stack_b);
		}
		else if (stack_a->head->next->data == pivot)
		{
			// printf("스택a데이터: %d\n", stack_a->head->next->data);
			pb(stack_a, stack_b);
			if (check_remain_pivot(*stack_a, pivot)) // a에서 b로 넘길 노드가 남아 있다면 피봇은 스택 맨 아래에 잠시 두어 나머지 노드가 넘어오면 다시 맨 위로 올림
				rb(stack_b);
		}
		else
			ra(stack_a);
	}
	if (stack_a->head->next->data != pivot)
		rra(stack_a); // a에서 b로 넘길 노드가 남아 있다면 피봇은 스택 맨 아래에 잠시 두어 나머지 노드가 넘어오면 다시 맨 위로 올림
	sort_stack_a(stack_a, stack_b, pivot + 1, end);
}

// 기능: 스택b에서 피봇별로 나뉜값을 스택a로 보냄, 리턴: void
// void			sort_stack_b(t_list *stack_a, t_list *stack_b, int *sorted_node)
// {

// }

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
			min = tmp->data;
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
		if (tmp->pivot && p_min > tmp->pivot)
			p_min = tmp->pivot;
		tmp = tmp->next;
	}
	printf("p_min %d\n", p_min);
	return (p_min);
}

// 기능: 스택을 정렬하기 위한 알고리즘, 리턴: void
void			algorithm(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	if (check_stack_a(stack_a) && (stack_b->count == 0)) // 스택a가 정렬되어 있고 스택b가 비어 있다면 리턴
		return ;
	else if (!check_stack_a(stack_a))
		sort_stack_a(stack_a, stack_b, find_min_data(*stack_a), find_min_pivot(*stack_a));
	// else if (stack_b->count != 0)
	// {
	// 	sort_stack_b(stack_a, stack_b, sorted_node);
	// }
	// if (stack_a->count - stack_a->sorted_num > 3) // 스택a의 개수에서 정렬된 개수를 뺴서 정렬이 안 된 개수를 추출
	// {
	// 	// TODO: 스택a가 저장된 후의 일 처리
	// 	sort_stack_a(stack_a, stack_b, sorted_node, stack_a->count); // 스택a를 인수가 3개 이하로 있을 때까지 반복 호출
		
	// }
	// else
	// 	sort_three_node_a(stack_a);
	// algorithm(stack_a, stack_b, sorted_node); // 탈출조건이 도달할 때 까지 반복
}

// 기능: 스택a에서 처음 정렬이 이루어지기까지 수행, 리턴: void
void			set_algorithm(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	if (check_stack_a(stack_a))
		return ;
	else if (!check_stack_a(stack_a))
		sort_stack_a(stack_a, stack_b, sorted_node[0], sorted_node[stack_a->count - 1]); // 처음에 start는 제일 작은 노드, end는 제일 큰 노드
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
	// // algorithm(&stack_a, &stack_b, sorted_node);
	printf("\n A \n");
	view_node(&stack_a);
	printf("\n");
	printf("\n B \n");
	view_node(&stack_b);
	free(sorted_node);
	return (0);
}
