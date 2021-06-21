#include "ft_push_swap.h"

// 기능: 스택a 또는 스택b의 최상위 2개 자리를 바꿈, 리턴: void
void            sa(t_list *stack)
{
    int tmp;

    if (stack->count < 2)
        return ;
    tmp = stack->head->next->data; // tmp에 스택의 첫번째 노드의 데이터 저장
    stack->head->next->data = stack->head->next->next->data; // 스택의 첫번째 노드의 데이터에 두번째 노드의 데이터 저장
    stack->head->next->next->data = tmp; // 스택의 두번째 노드의 데이터에 첫번째 노드의 데이터 저장
    printf("sa\n");
    rst += 1;
}

void            sb(t_list *stack)
{
    int tmp;

    if (stack->count < 2)
        return ;
    tmp = stack->head->next->data; // tmp에 스택의 첫번째 노드의 데이터 저장
    stack->head->next->data = stack->head->next->next->data; // 스택의 첫번째 노드의 데이터에 두번째 노드의 데이터 저장
    stack->head->next->next->data = tmp; // 스택의 두번째 노드의 데이터에 첫번째 노드의 데이터 저장
    printf("sb\n");
    rst += 1;
}

// 기능 : 스택a와 스택b 둘다 취상위 2개 자리를 바꿈, 리턴: void
void            ss(t_list *stack_a, t_list *stack_b)
{
    int tmp_a;
    int tmp_b;

    if (stack_a->count < 2 || stack_b->count < 2)
        return ;
    tmp_a = stack_a->head->next->data; // tmp에 스택의 첫번째 노드의 데이터 저장
    stack_a->head->next->data = stack_a->head->next->next->data; // 스택의 첫번째 노드의 데이터에 두번째 노드의 데이터 저장
    stack_a->head->next->next->data = tmp_a; // 스택의 두번째 노드의 데이터에 첫번째 노드의 데이터 저장
    tmp_b = stack_b->head->next->data; // tmp에 스택의 첫번째 노드의 데이터 저장
    stack_b->head->next->data = stack_b->head->next->next->data; // 스택의 첫번째 노드의 데이터에 두번째 노드의 데이터 저장
    stack_b->head->next->next->data = tmp_a; // 스택의 두번째 노드의 데이터에 첫번째 노드의 데이터 저장
    printf("ss\n");
    rst += 1;
}
