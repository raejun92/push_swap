#include "ft_push_swap.h"

// 기능: 배열의 중간 데이터를 출력, 리턴: 배열 중간의 데이터
int				find_middle_data(int *sorted_node, t_list stack_a)
{
	int i;
	int data;

	i = intlen(sorted_node, stack_a.count);
	if ((i + 1) % 2 != 0 && i % 2 != 0) // ex) 1 4 5가 들어오면 data는 4 출력, i = 1
        i = i / 2 + 1;
    else
        i = i / 2;
	data = sorted_node[i];
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

// 기능: 스택을 정렬하기 위한 알고리즘, 리턴: void
void			algorithm(t_list *stack_a, t_list *stack_b, int *sorted_node)
{
	int middle_data;

	middle_data = find_middle_data(sorted_node, *stack_a); // 배열의 가운데 데이터 추출
	divide_half(stack_a, stack_b, middle_data); // 가운데 데이터를 기준으로 스택을 반으로 나눔
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
	stack_a.name = 'a';
	stack_b.name = 'b';
	sorted_node = (int *)malloc(sizeof(int) * (argc - 1));
	while (*(++argv))
		check_input(*argv, &stack_a);
	make_sorted_array(stack_a, sorted_node);
	algorithm(&stack_a, &stack_b, sorted_node);
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
