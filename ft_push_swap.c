#include "ft_push_swap.h"

// 기능: 정렬된 노드 개수 확인, 리턴: 정렬된 노드 개수
int				check_num(t_list *stack)
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
	int data;
	
	data = sorted_node[len];
	return (data);
}

// 기능: 가운데 데이터를 기준으로 스택a, b의 값을 나눔, 리턴: void
void			divide_half_a(t_list *stack_a, t_list *stack_b, int middle_data)
{
	int	i;
	int	count;
 
	i = 0;
	count = stack_a->count / 2;
	while (count > i)
	{
		if (stack_a->head->next->data < middle_data)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra_rb(stack_a);
	}
}

// 기능: 스택이 정렬되어 있는지 확인, 리턴: 정렬되어 있으면 1 아니면 0
int			check_ascending(t_list stack_a)
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

static void		sort_three_node_a2(t_list *stack)
{
	if (check_ascending(*stack))
		return ;
	// 3 1 2
	if (stack->head->next->next->next->data > stack->head->next->next->data &&
		stack->head->next->next->next->data < stack->head->next->data)
		{
			ra_rb(stack);
			printf("ra\n");
		}
	// 3 2 1
	else if (stack->head->next->next->data > stack->head->next->next->next->data &&
		stack->head->next->next->data < stack->head->next->data)
		{
			sa_sb(stack);
			printf("sa\n");
			rra_rrb(stack);
			printf("rra\n");
		}
	stack->head->next->check = 1;
	stack->head->next->next->check = 1;
	stack->head->next->next->next->check = 1;
}

// 기능: 3개 노드 정렬, 리턴: void
void			sort_three_node_a(t_list *stack)
{
	if (check_ascending(*stack))
		return ;
	// 1 3 2
	if (stack->head->next->next->next->data > stack->head->next->data &&
		stack->head->next->next->next->data < stack->head->next->next->data)
		{
			sa_sb(stack);
			printf("sa\n");
			ra_rb(stack);
			printf("ra\n");
		}
	// 2 1 3
	else if (stack->head->next->data > stack->head->next->next->data &&
		stack->head->next->data < stack->head->next->next->next->data)
		{
			sa_sb(stack);
			printf("sa\n");
		}
	// 2 3 1
	else if (stack->head->next->data > stack->head->next->next->next->data &&
		stack->head->next->data < stack->head->next->next->data)
		{
			rra_rrb(stack);
			printf("rra\n");
		}
	sort_three_node_a2(stack);	
}

// 기능: 노드 2개 정렬, 리턴: void
void			sort_two_node_a(t_list *stack)
{
	if (stack->head->next->data > stack->head->next->next->data)
	{
		sa_sb(stack);
		printf("sa\n");
	}
	stack->head->next->check = 1;
	stack->head->next->next->check = 1;
}

// 기능: 피봇 설정, 리턴: void
void			set_pivot(t_list *stack_a, int middle_data)
{
	t_node *pivot;

	pivot = stack_a->head->next;
	while (pivot != stack_a->tail)
	{
		if (pivot->data == middle_data)
			pivot->pivot = 1;
		pivot = pivot->next;
	}
}

// 기능: 스택a를 정렬, 리턴: void
void			sort_stack_a(t_list *stack_a, t_list *stack_b, int *sorted_node, int len)
{
	int middle_data;
	// TODO: 반복시키기
	if (stack_a->count - check_num(stack_a) == 3) // 스택a에 정렬 안 된 노드가 3개이면 3개 정렬
	{
		sort_three_node_a(stack_a);
		return ;
	}
	else if (stack_a->count - check_num(stack_a) == 2) // 스택a에 정렬 안 된 노드가 2개이면  2개 정렬
	{
		sort_two_node_a(stack_a);
		return ;
	}
	else
	{
		len = stack_a->count - check_num(stack_a) / 2;
		middle_data = find_middle_data(sorted_node, len); // 배열의 가운데 데이터 추출
		set_pivot(stack_a, middle_data); // 중간값을 피봇이라고 표시
		divide_half_a(stack_a, stack_b, middle_data); // 가운데 데이터를 기준으로 스택을 반으로 나눔
		sort_stack_a(stack_a, stack_b, sorted_node, len); // 노드가 2 또는 3개가 될 때까지 반복
	}
}

// 기능: 스택을 정렬하기 위한 알고리즘, 리턴: void
void			algorithm(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	/* MEMO: 1. 스택a가 정렬되어 있고 스택b에 값이 아무것도 없다면 종결
			 2. 스택a를 정렬 시킴
			 3. 스택b를 정렬 시킴
	*/
	if (check_ascending(*stack_a) && (stack_b->count == 0)) // 스택a가 정렬되어 있고 스택b가 비어 있다면 리턴
		return ;
	else if (!check_ascending(*stack_a))
	{
		sort_stack_a(stack_a, stack_b, sorted_node, stack_a->count);
	}

	// if (stack_a->count - stack_a->sorted_num > 3) // 스택a의 개수에서 정렬된 개수를 뺴서 정렬이 안 된 개수를 추출
	// {
	// 	// TODO: 스택a가 저장된 후의 일 처리
	// 	sort_stack_a(stack_a, stack_b, sorted_node, stack_a->count); // 스택a를 인수가 3개 이하로 있을 때까지 반복 호출
		
	// }
	// else
	// 	sort_three_node_a(stack_a);
}

int				main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	int		*sorted_node;

	if (argc < 3)
		return (0);
	init_list(&stack_a);
	init_list(&stack_b);
	sorted_node = (int *)malloc(sizeof(int) * (argc - 1));
	while (*(++argv))
		check_input(*argv, &stack_a);
	make_sorted_array(stack_a, sorted_node);
	algorithm(&stack_a, &stack_b, sorted_node);
	printf("\n");
	view_node(&stack_a);
	printf("\n");
	view_node(&stack_b);
	// printf("\n");
	// add_node(&stack_b, 10);
	// add_node(&stack_b, 5);
	// add_node(&stack_b, 29);
	// view_node(&stack_b);
	// printf("\n");
	// rrr(&stack_a, &stack_b);
	// view_node(&stack_a);
	// printf("\n");
	// view_node(&stack_b);
	free(sorted_node);
	return (0);
}
