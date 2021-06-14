#include "ft_push_swap.h"

// 기능: 노드의 데이터를 배열에 넣음, 리턴: void
void			input_array(t_list stack_a, int *sorted_node)
{
	while (stack_a.head != stack_a.tail->prev)
	{
		*sorted_node = stack_a.head->next->data;
		stack_a.head = stack_a.head->next;
		printf("D %d\n", *sorted_node);
		sorted_node++;
	}
}

// 기능: 노드를 배열로 오름차순 정렬, 리턴: void
void			sort_ascending(t_list stack_a, int *sorted_node)
{
	int i;
	int j;
	int	size;
	int	tmp;

	input_array(stack_a, sorted_node);
	size = 0;
	i = 0;
	while (sorted_node[size])
		size++;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (sorted_node[j] == sorted_node[j + 1])
				error_msg();
			if (sorted_node[j] > sorted_node[j + 1])
			{
				tmp = sorted_node[j];
				sorted_node[j] = sorted_node[j + 1];
				sorted_node[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

// 기능: 배열의 중간 데이터를 출력, 리턴: 배열 중간의 데이터
int				find_middle_data(int *sorted_node)
{
	int i;
	int data;

	i = 0;
	while (sorted_node[i])
		i++;
	if ((i + 1) % 2 != 0 && i % 2 != 0) // ex) 1 4 5가 들어오면 data는 4 출력, i = 1
        i = i / 2 + 1;
    else
        i = i / 2;
	data = sorted_node[i];
	return (data);
}

// 기능: 노드를 미리 정렬시켜 놓은 배열을 만들고 추가 기능 예정, 리턴: void
void			make_sorted_array(t_list *stack_a, int *sorted_node)
{
	int middle_data;

	sort_ascending(*stack_a, sorted_node); // 배열에 오름차순 정렬
	middle_data = find_middle_data(sorted_node);
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
	make_sorted_array(&stack_a, sorted_node);
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
