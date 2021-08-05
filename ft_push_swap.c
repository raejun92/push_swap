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
	while (*(++argv)) // ./a.out 이후 검사
		check_input(*argv, &stack_a);
	make_sorted_array(stack_a, sorted_node);
	enroll_rank(&stack_a, sorted_node);
	if (argc <= 4 || argc == 6)
		sort_first_a(&stack_a, &stack_b, sorted_node);
	else
		algorithm(&stack_a, &stack_b);
	// process_command(&stack_a);
	// printf("\n");
	// printf("A\n");
	// view_node(&stack_a);
	// printf("\n");
	// printf("B\n");
	// view_node(&stack_b);
	// rst = 0;
	// printf("\nrst: %d", rst);
	
	free(sorted_node);
	return (0);
}