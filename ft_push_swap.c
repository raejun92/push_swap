#include "ft_push_swap.h"

int		check_ascending(t_list stack_a)
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

int			main(int argc, char **argv)
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
	/* TODO: 흐름
	29 | 18 | 47 | 50 | 19 | 49 | 27 | 502 | 184 | 1293 | 1824 | 1 | 291
	랭킹: 5 | 2 | 6 | 8 | 3 | 7 | 4 | 11 | 9 | 12 | 13 | 1 | 10
	
	값이 아닌 랭킹으로 정렬하자
	피봇은 (가장 큰 랭킹 + 가장 작은 랭킹) / 2로 구한다
	스택a에서 더 이상 pivot > 스택a의 랭킹인 값이 없을 때까지 찾는다
	설정된 피봇값이 스택b를 나누는 기준이 된다
	*/
}