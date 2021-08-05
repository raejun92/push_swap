#include "ft_push_swap.h"

// 기능: b의 맨 위 1개를 a의 맨 위로 이동, 리턴: void
void			pa(t_list *stack_a, t_list *stack_b)
{
	t_node	*cur;
	
	if (stack_b->count == 0)
	{
		printf("b는 비어있음");
		exit (0);
	}
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
	rst += 1;
}

// 기능: a의 맨 위 1개를 b의 맨 위로 이동, 리턴: void
void			pb(t_list *stack_a, t_list *stack_b)
{
	t_node		*cur;

	if (stack_a->count == 0)
	{
		printf("a는 비어있음");
		exit (0);
	}
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
	rst += 1;
}

// void			remove_node(t_list *list)
// {
// 	t_node *cur;

// 	cur = list->head->next;
// 	cur->prev->next = cur->next; // 이전 노드의 next를 cur의 다음 노드로 설정
// 	cur->next->prev = cur->prev; // 다음 노드의 prev를 cur의 이전 노드로 설정
// 	free(cur);
// 	list->count--;
// }

// void			add_node2(t_list *list, t_node *cur)
// {
// 	cur->prev = list->head;
// 	cur->next = list->head->next;
// 	list->head->next->prev = cur;
// 	list->head->next = cur;
// 	list->count++;
// }