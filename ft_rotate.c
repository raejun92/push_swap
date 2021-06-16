#include "ft_push_swap.h"

// ra: a의 모든 요소 위로 로테이션
// rb: b의 모든 요소 위로 로테이션
// rr: ra와 rb 동시 수행
// 기능: a 또는 b의 요소 위로 로테이션, 리턴: void
void			ra_rb(t_list *stack)
{
	t_node *tmp;

	tmp = stack->head->next; // 첫번째 노드를 임시 저장, 임시 저장하지 않으면 주소를 잃음
	stack->head->next = stack->head->next->next; // 헤더는 두번째 노드를 기리킴
	stack->head->next->next->prev = stack->head->next->prev; // 두번째였던 노드는 첫번째였던 노드가 가리켰던 head를 가리킴
	tmp->prev = stack->tail->prev; // 첫번째였던 노드의 prev는 테일이 가리키던 곳을 가리킴
	stack->tail->prev->next = tmp; // 테일을 가리키던 맨 끝 노드는 헤드가 가리키던 맨 앞 노드를 가리킴
	tmp->next = stack->tail; // 첫번째였던 노드는 테일을 가리킴
	stack->tail->prev = tmp; // 테일의 prev는 첫번째였던 노드를 가리킴
	if (stack->name == 'a')
		printf("ra\n");
	else
		printf("rb\n");
}

// 기능: a와 b의 요소 위로 로테이션, 리턴: void
void			rr(t_list *stack_a, t_list *stack_b)
{
	ra_rb(stack_a);
	ra_rb(stack_b);
}