#include "ft_push_swap.h"

// 기능: 스택a 또는 스택b의 최상위 2개 자리를 바꿈, 리턴: void
void            sa_sb(t_list *stack)
{
    int tmp;

    tmp = stack->head->next->data; // tmp에 스택의 첫번째 노드의 데이터 저장
    stack->head->next->data = stack->head->next->next->data; // 스택의 첫번째 노드의 데이터에 두번째 노드의 데이터 저장
    stack->head->next->next->data = tmp; // 스택의 두번째 노드의 데이터에 첫번째 노드의 데이터 저장
    if (stack->name == 'a')
		printf("sa\n");
	else
		printf("sb\n");
}

// 기능 : 스택a와 스택b 둘다 취상위 2개 자리를 바꿈, 리턴: void
void            ss(t_list *stack_a, t_list *stack_b)
{
    int tmp;

    sa_sb(stack_a);
    sa_sb(stack_b);
}
