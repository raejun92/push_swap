#include "ft_push_swap.h"

// 기능: a 또는 b의 요소 위로 로테이션, 리턴: void
void			ra(t_list *stack)
{
	t_node *tmp;

	if (stack->count == 0)
		return ;
	tmp = stack->head->next; // 첫번째 노드를 임시 저장, 임시 저장하지 않으면 주소를 잃음
	stack->head->next->next->prev = stack->head->next->prev; // 두번째였던 노드는 첫번째였던 노드가 가리켰던 head를 가리킴
	stack->head->next = stack->head->next->next; // 헤더는 두번째 노드를 기리킴
	tmp->prev = stack->tail->prev; // 첫번째였던 노드의 prev는 테일이 가리키던 곳을 가리킴
	tmp->next = stack->tail; // 첫번째였던 노드는 테일을 가리킴
	stack->tail->prev->next = tmp; // 테일을 가리키던 맨 끝 노드는 헤드가 가리키던 맨 앞 노드를 가리킴
	stack->tail->prev = tmp; // 테일의 prev는 첫번째였던 노드를 가리킴
	write(1, "ra\n", 3);
}

void			rb(t_list *stack)
{
	t_node *tmp;

	if (stack->count == 0)
		return ;
	tmp = stack->head->next; // 첫번째 노드를 임시 저장, 임시 저장하지 않으면 주소를 잃음
	stack->head->next->next->prev = stack->head->next->prev; // 두번째였던 노드는 첫번째였던 노드가 가리켰던 head를 가리킴
	stack->head->next = stack->head->next->next; // 헤더는 두번째 노드를 기리킴
	tmp->prev = stack->tail->prev; // 첫번째였던 노드의 prev는 테일이 가리키던 곳을 가리킴
	tmp->next = stack->tail; // 첫번째였던 노드는 테일을 가리킴
	stack->tail->prev->next = tmp; // 테일을 가리키던 맨 끝 노드는 헤드가 가리키던 맨 앞 노드를 가리킴
	stack->tail->prev = tmp; // 테일의 prev는 첫번째였던 노드를 가리킴
	write(1, "rb\n", 3);
}

// 기능: a와 b의 요소 위로 로테이션, 리턴: void
void			rr(t_list *stack_a, t_list *stack_b)
{
	t_node *tmp_a;
	t_node *tmp_b;

	if (stack_a->count == 0 || stack_b->count == 0)
		return ;
	tmp_a = stack_a->head->next; // 첫번째 노드를 임시 저장, 임시 저장하지 않으면 주소를 잃음
	stack_a->head->next->next->prev = stack_a->head->next->prev; // 두번째였던 노드는 첫번째였던 노드가 가리켰던 head를 가리킴
	stack_a->head->next = stack_a->head->next->next; // 헤더는 두번째 노드를 기리킴
	tmp_a->prev = stack_a->tail->prev; // 첫번째였던 노드의 prev는 테일이 가리키던 곳을 가리킴
	tmp_a->next = stack_a->tail; // 첫번째였던 노드는 테일을 가리킴
	stack_a->tail->prev->next = tmp_a; // 테일을 가리키던 맨 끝 노드는 헤드가 가리키던 맨 앞 노드를 가리킴
	stack_a->tail->prev = tmp_a; // 테일의 prev는 첫번째였던 노드를 가리킴
	tmp_b = stack_b->head->next; // 첫번째 노드를 임시 저장, 임시 저장하지 않으면 주소를 잃음
	stack_b->head->next->next->prev = stack_b->head->next->prev; // 두번째였던 노드는 첫번째였던 노드가 가리켰던 head를 가리킴
	stack_b->head->next = stack_b->head->next->next; // 헤더는 두번째 노드를 기리킴
	tmp_b->prev = stack_b->tail->prev; // 첫번째였던 노드의 prev는 테일이 가리키던 곳을 가리킴
	tmp_b->next = stack_b->tail; // 첫번째였던 노드는 테일을 가리킴
	stack_b->tail->prev->next = tmp_b; // 테일을 가리키던 맨 끝 노드는 헤드가 가리키던 맨 앞 노드를 가리킴
	stack_b->tail->prev = tmp_b; // 테일의 prev는 첫번째였던 노드를 가리킴
	write(1, "rr\n", 3);
}