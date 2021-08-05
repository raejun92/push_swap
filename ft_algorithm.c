#include "ft_push_swap.h"

// 기능: 정렬이 안 된 노드가 3개 이하일 때 정렬 시킴, 리턴: void
void			check_and_sort(t_list *stack_a)
{
	int	cnt;

	if (check_ascending(*stack_a)) // a가 정렬 되어 있으면 리턴
		return ;
	cnt = out_of_alignment(stack_a); // 정렬 되지 않은 노드의 개수
	if (stack_a->count == 2 || cnt == 2)
		sort_two_node_a(stack_a);
	else if (stack_a->count == 3)
		sort_three_node_a(stack_a);
	if (cnt == 3)
		sort_three(stack_a);
}

// 기능: 스택을 정렬시키는 알고리즘, 리턴: void
void			algorithm(t_list *stack_a, t_list *stack_b)
{
	if (check_ascending(*stack_a) && stack_b->count == 0) // 스택a가 정렬되어 있고 스택b에 아무것도 없다면 조건 만족
		return ;
	else if (!check_ascending(*stack_a)) // 스택a가 정렬되어 있지 않다면 정렬
		sort_stack_a(stack_a, stack_b, stack_a_min(*stack_a), stack_a_max(*stack_a));
	else if (check_ascending(*stack_a) && stack_b->count != 0) // 스택a가 정렬되어 있고 스택b에 노드가 존재한다면 b정렬
		sort_stack_b(stack_a, stack_b, stack_b_max_pivot(*stack_b), stack_b_max(*stack_b));
	check_and_sort(stack_a);
	if (check_ascending(*stack_a))
		set_sort(stack_a);
	algorithm(stack_a, stack_b);
}