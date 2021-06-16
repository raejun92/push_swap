#include "ft_push_swap.h"

// 기능: 배열의 중간 데이터를 출력, 리턴: 배열 중간의 데이터
int				find_middle_data(int *sorted_node, int *len)
{
	int data;

	if ((*len + 1) % 2 != 0 && *len % 2 != 0) // ex) 1 4 5가 들어오면 data는 4 출력, i = 1
        *len = *len / 2 + 1;
    else
        *len = *len / 2;
	data = sorted_node[*len];
	return (data);
}

// 기능: 가운데 데이터를 기준으로 스택a, b의 값을 나눔, 리턴: void
void			divide_half(t_list *stack_a, t_list *stack_b, int middle_data)
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
int			check_sorted_stack(t_list stack_a)
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

// 기능: 3개 노드 정렬, 리턴: void
void			sort_three_node_a(t_list *stack)
{
	while (!(check_sorted_stack(*stack)))
	{
		if (stack->head->next->data > stack->head->next->next->data)
		{
			sa_sb(stack);
			printf("sa\n");
			if (check_sorted_stack(*stack))
				return ;
			rra_rrb(stack);
			printf("rra\n");
		}
		else
		{
			ra_rb(stack);
			printf("ra\n");
		}
	}
}

// 기능: 알고리즘 기능 반복, 리턴: void
void			repeat_algorithm(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	if (stack_a->count <= 3)
		sort_three_node(stack_a);
	
}

// 기능: 스택을 정렬하기 위한 알고리즘, 리턴: void
void			algorithm(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	int middle_data;
	int len;

	middle_data = 0;
	len = stack_a->count;
	if (check_sorted_stack(*stack_a)) // 정렬되어 있으면 리턴
		return ;
	if (stack_a->count > 3)
	{
		middle_data = find_middle_data(sorted_node, &len); // 배열의 가운데 데이터 추출
		divide_half(stack_a, stack_b, middle_data); // 가운데 데이터를 기준으로 스택을 반으로 나눔
		repeat_algorithm(stack_a, stack_b, sorted_node); // 스택a 정렬
	}
	else
		sort_three_node_a(stack_a);
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
