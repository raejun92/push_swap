#include "ft_push_swap.h"

// pa: b의 맨 위 1개를 a로 이동
// pb: a의 맨 위 1개를 b로 이동

// 기능: b의 맨 위 1개를 a의 맨 위로 이동, 리턴: void
void			pa(t_list *stack_a, t_list *stack_b)
{
	t_node *tmp_b;

	if (!stack_b)
		exit (0);	
	tmp_b = stack_b->head->next; // b의 첫번째 노드 임시 저장
	stack_b->head->next = stack_b->head->next->next; // b의 헤드가 두번째 노드를 가리켜 첫번째로 이동
	stack_b->head->next->next->prev = stack_b->head; // b의 두번째 노드는 헤드를 가리켜 첫번째 노드가 됨
	stack_b->count--;
	tmp_b->prev = stack_a->head; // 새로운 노드를 헤드를 가리켜 첫번째 노드가 됨
	tmp_b->next = stack_a->head->next; // 새로운 노드의 다음은 첫번째였던 노드를 가리킴
	stack_a->head->next = tmp_b; // 헤드는 새로운 노드를 가리킴
	stack_a->head->next->prev = tmp_b; // 첫번째였던 노드는 새로운 노드를 가리킴
	stack_a->count++;
}

// 기능: a의 맨 위 1개를 b의 맨 위로 이동, 리턴: void
void			pb(t_list *stack_a, t_list *stack_b)
{
	t_node *tmp_a;

	if (!stack_a)
		exit (0);
	tmp_a = stack_a->head->next;
	stack_a->head->next = stack_a->head->next->next;
	stack_a->head->next->next->prev = stack_a->head;
	stack_a->count--;
	tmp_a->prev = stack_b->head;
	tmp_a->next = stack_b->head->next;
	stack_b->head->next = tmp_a;
	stack_b->head->next->prev = tmp_a;
	stack_b->count++;
}