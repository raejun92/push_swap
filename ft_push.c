#include "ft_push_swap.h"

// 기능: b의 맨 위 1개를 a의 맨 위로 이동, 리턴: void
void			pa(t_list *stack_a, t_list *stack_b)
{
	t_node	*cur;
	
	if (stack_b->count == 0)
		return ;
	cur = stack_b->head->next;
	cur->prev->next = cur->next; // 이전 노드의 next를 cur의 다음 노드로 설정
	cur->next->prev = cur->prev; // 다음 노드의 prev를 cur의 이전 노드로 설정
	stack_b->count--;
	cur->prev = stack_a->head;
	cur->next = stack_a->head->next;
	stack_a->head->next->prev = cur;
	stack_a->head->next = cur;
	stack_a->count++;
	write(1, "pa\n", 3);
}

// 기능: a의 맨 위 1개를 b의 맨 위로 이동, 리턴: void
void			pb(t_list *stack_a, t_list *stack_b)
{
	t_node		*cur;

	if (stack_a->count == 0)
		return ;
	cur = stack_a->head->next;
	cur->prev->next = cur->next; // 이전 노드의 next를 cur의 다음 노드로 설정
	cur->next->prev = cur->prev; // 다음 노드의 prev를 cur의 이전 노드로 설정
	stack_a->count--;
	cur->prev = stack_b->head;
	cur->next = stack_b->head->next;
	stack_b->head->next->prev = cur;
	stack_b->head->next = cur;
	stack_b->count++;
	write(1, "pb\n", 3);
}