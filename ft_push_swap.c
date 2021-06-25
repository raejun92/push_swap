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
		{
			pivot->pivot = 1;
			printf("pivot %d\n", pivot->data);
		}
		pivot = pivot->next;
	}
}

static void		first_sort_a(t_list *stack_a, t_list *stack_b, int *sorted_node, int index)
{
	if (stack_a->count == 3) // 스택a에 초기 3개 노드 정렬
		sort_three_node_a(stack_a);
	else if (stack_a->count == 2) // 스택a에 초기 2개 노드 정렬
		sort_two_node_a(stack_a);
	else if (stack_a->count == 5)  // 스택a에 초기 5개 노드 정렬
		sort_five_node_a(stack_a, stack_b, sorted_node, index);
}

// 기능: 스택a가 모두 정렬이 될 때까지 반복 수행, 리턴: void
void			sort_stack_a(t_list *stack_a, t_list *stack_b, int start, int end)
{
	int		pivot;

	if (start > end)
		return ;
	pivot = (start + end) / 2;
	set_pivot(stack_a, pivot);
	while (1) // 노드 <= pivot인 값이 하나라도 남아 있는지 확인
	{
		if (stack_a->head->next->data < pivot)
			pb(stack_a, stack_b);
		else if (stack_a->head->next->data == pivot)
		{
			pb(stack_a, stack_b);
			// 노드 <= pivot인 값이 하나라도 남아 있으면 rb
		}
		else
			ra(stack_a);
	}

}

// 기능: 스택b에서 피봇별로 나뉜값을 스택a로 보냄, 리턴: void
// void			sort_stack_b(t_list *stack_a, t_list *stack_b, int *sorted_node)
// {

// }

// 기능: 스택을 정렬하기 위한 알고리즘, 리턴: void
void			algorithm(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	/* MEMO: 1. 스택a가 정렬되어 있고 스택b에 값이 아무것도 없다면 종결
			 2. 스택a를 정렬 시킴
			 3. 스택b를 정렬 시킴
	*/
	if (check_stack_a(stack_a) && (stack_b->count == 0)) // 스택a가 정렬되어 있고 스택b가 비어 있다면 리턴
		return ;
	else if (!check_stack_a(stack_a))
		sort_stack_a(stack_a, stack_b, sorted_node, 0);
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

void			set_algorithm(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	if (check_stack_a(stack_a) && (stack_b->count == 0))
		return ;
	else if (!check_stack_a(stack_a))
		sort_stack_a(stack_a, stack_b, sorted_node[0], sorted_node[stack_a->count - 1]);
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
	algorithm(&stack_a, &stack_b, sorted_node);
	// printf("\n");
	// view_node(&stack_a);
	// printf("\n");
	// view_node(&stack_b);
	free(sorted_node);
	return (0);
}
