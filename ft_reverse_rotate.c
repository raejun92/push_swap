#include "ft_push_swap.h"

// REVERSE ROTATE
// rra: a의 모든 요소 아래로 로테이션
// rrb: b의 모든 요소 아래로 로테이션
// rrr: rra와 rrb 동시 수행

// 기능: a 또는 b 스택의 모든 요소 아래로 로테이션, 리턴: void
void			rra_rrb(t_list *stack)
{
	t_node *tmp;

	tmp = stack->tail->prev; // 맨 뒤 노드를 임시 저장, 임시 저장하지 않으면 주소를 잃음
	stack->tail->prev->prev->next = stack->tail->prev->next; // 뒤에서 2번째 노드를 테일을 가리키게 함
	stack->tail->prev = stack->tail->prev->prev; // 테일이 맨 뒤에서 앞 노드를 가리키게 함
	tmp->prev = stack->head->next->prev; // 맨 뒤였던 노드의 prev는 헤드를 가리킴
	tmp->next = stack->head->next; // 맨 뒤였던 노드의 next는 첫번째였던(헤드가 가리키던) 노드를 가리킴
	stack->head->next->prev = tmp; // 첫번째였던 노드의 prev는 맨 뒤였던 노드를 가리킴
	stack->head->next = tmp; // 헤드는 맨 뒤였던 노드를 가리킴
}

// 기능: a와 b 스택의 모든 요소 아래로 로페이션, 리턴: void
void			rrr(t_list *stack_a, t_list *stack_b)
{
	rra_rrb(stack_a);
	rra_rrb(stack_b);
}