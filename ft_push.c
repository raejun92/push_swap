#include "ft_push_swap.h"

// pa: b의 맨 위 1개를 a로 이동
// pb: a의 맨 위 1개를 b로 이동

// 기능: b의 맨 위 1개를 a의 맨 위로 이동, 리턴: void
void			pa(t_list *stack_a, t_list *stack_b)
{
	int tmp;
	t_node *cur;

	if (!stack_b)
		exit (0);
	tmp = stack_b->head->next->data; // 스택b의 첫번째 노드의 데이터를 저장
	cur = stack_b->head->next; // 스택b의 첫번째 노드를 저장
	remove_node(stack_b, cur); // 스택b의 첫번째 노드를 삭제
	add_node(stack_a, tmp); // 스택b에서 저장한 데이터를 스택a에 추가

/* 	tmp_b = stack_b->head->next; // b의 첫번째 노드 임시 저장
	stack_b->head->next = stack_b->head->next->next; // b의 헤드가 두번째 노드를 가리켜 첫번째로 이동
	
	tmp_a = stack_a->head->next; // a의 첫번째 노드 임시 저장
	stack_a->head->next = tmp_b; // 
	tmp_b->next = tmp_a; */
}

// 기능: a의 맨 위 1개를 b의 맨 위로 이동, 리턴: void
/* void			pb(t_list *stack_a, t_list *stack_b)
{
	t_node *tmp_a;
	t_node *tmp_b;

	if (!stack_a)
		exit (0);
	tmp_a = stack_a->head->next;
	stack_a->head->next = stack_a->head->next->next;
	tmp_b = stack_b->head->next;
	stack_b->head->next = tmp_a;
	tmp_a->next = tmp_a;
} */