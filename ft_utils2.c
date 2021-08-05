#include "ft_push_swap.h"

void			error_msg()
{
	write(2, "Error\n", 6);
	exit(0);
}

// 기능: 피봇인 노드 1로 설정, 리턴: void
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