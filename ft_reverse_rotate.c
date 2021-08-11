#include "ft_push_swap.h"

// 기능: a 또는 b 스택의 모든 요소 아래로 로테이션, 리턴: void
void			rra(t_list *stack)
{
	t_node *tmp;

	if (stack->count == 0)
		return ;
	tmp = stack->tail->prev; // 맨 뒤 노드를 임시 저장, 임시 저장하지 않으면 주소를 잃음
	stack->tail->prev->prev->next = stack->tail->prev->next; // 뒤에서 2번째 노드를 테일을 가리키게 함
	stack->tail->prev = stack->tail->prev->prev; // 테일이 맨 뒤에서 앞 노드를 가리키게 함
	tmp->prev = stack->head->next->prev; // 맨 뒤였던 노드의 prev는 헤드를 가리킴
	tmp->next = stack->head->next; // 맨 뒤였던 노드의 next는 첫번째였던(헤드가 가리키던) 노드를 가리킴
	stack->head->next->prev = tmp; // 첫번째였던 노드의 prev는 맨 뒤였던 노드를 가리킴
	stack->head->next = tmp; // 헤드는 맨 뒤였던 노드를 가리킴
	write(1, "rra\n", 4);
}

void			rrb(t_list *stack)
{
	t_node *tmp;

	if (stack->count == 0)
		return ;
	tmp = stack->tail->prev; // 맨 뒤 노드를 임시 저장, 임시 저장하지 않으면 주소를 잃음
	stack->tail->prev->prev->next = stack->tail->prev->next; // 뒤에서 2번째 노드를 테일을 가리키게 함
	stack->tail->prev = stack->tail->prev->prev; // 테일이 맨 뒤에서 앞 노드를 가리키게 함
	tmp->prev = stack->head->next->prev; // 맨 뒤였던 노드의 prev는 헤드를 가리킴
	tmp->next = stack->head->next; // 맨 뒤였던 노드의 next는 첫번째였던(헤드가 가리키던) 노드를 가리킴
	stack->head->next->prev = tmp; // 첫번째였던 노드의 prev는 맨 뒤였던 노드를 가리킴
	stack->head->next = tmp; // 헤드는 맨 뒤였던 노드를 가리킴
	write(1, "rrb\n", 4);
}

// 기능: a와 b 스택의 모든 요소 아래로 로페이션, 리턴: void
void			rrr(t_list *stack_a, t_list *stack_b)
{
	t_node *tmp_a;
	t_node *tmp_b;

	if (stack_a->count == 0 || stack_b->count == 0)
		return ;
	tmp_a = stack_a->tail->prev; // 맨 뒤 노드를 임시 저장, 임시 저장하지 않으면 주소를 잃음
	stack_a->tail->prev->prev->next = stack_a->tail->prev->next; // 뒤에서 2번째 노드를 테일을 가리키게 함
	stack_a->tail->prev = stack_a->tail->prev->prev; // 테일이 맨 뒤에서 앞 노드를 가리키게 함
	tmp_a->prev = stack_a->head->next->prev; // 맨 뒤였던 노드의 prev는 헤드를 가리킴
	tmp_a->next = stack_a->head->next; // 맨 뒤였던 노드의 next는 첫번째였던(헤드가 가리키던) 노드를 가리킴
	stack_a->head->next->prev = tmp_a; // 첫번째였던 노드의 prev는 맨 뒤였던 노드를 가리킴
	stack_a->head->next = tmp_a; // 헤드는 맨 뒤였던 노드를 가리킴
	tmp_b = stack_b->tail->prev; // 맨 뒤 노드를 임시 저장, 임시 저장하지 않으면 주소를 잃음
	stack_b->tail->prev->prev->next = stack_b->tail->prev->next; // 뒤에서 2번째 노드를 테일을 가리키게 함
	stack_b->tail->prev = stack_b->tail->prev->prev; // 테일이 맨 뒤에서 앞 노드를 가리키게 함
	tmp_b->prev = stack_b->head->next->prev; // 맨 뒤였던 노드의 prev는 헤드를 가리킴
	tmp_b->next = stack_b->head->next; // 맨 뒤였던 노드의 next는 첫번째였던(헤드가 가리키던) 노드를 가리킴
	stack_b->head->next->prev = tmp_b; // 첫번째였던 노드의 prev는 맨 뒤였던 노드를 가리킴
	stack_b->head->next = tmp_b; // 헤드는 맨 뒤였던 노드를 가리킴
	write(1, "rrr\n", 4);
}