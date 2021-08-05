#include "ft_push_swap.h"

// 기능: 스택a 또는 스택b의 최상위 2개 자리를 바꿈, 리턴: void
void            sa(t_list *stack)
{
    int tmp_data;
    int tmp_rank;

    if (stack->count < 2)
        return ;
    tmp_data = stack->head->next->data; // tmp에 스택의 첫번째 노드의 데이터 저장
    stack->head->next->data = stack->head->next->next->data; // 스택의 첫번째 노드의 데이터에 두번째 노드의 데이터 저장
    stack->head->next->next->data = tmp_data; // 스택의 두번째 노드의 데이터에 첫번째 노드의 데이터 저장
    tmp_rank = stack->head->next->rank;
    stack->head->next->rank = stack->head->next->next->rank;
    stack->head->next->next->rank = tmp_rank;
    write(1, "sa\n", 3);
    rst += 1;
}

void            sb(t_list *stack)
{
    int tmp_data;
    int tmp_rank;

    if (stack->count < 2)
        return ;
    tmp_data = stack->head->next->data; // tmp에 스택의 첫번째 노드의 데이터 저장
    stack->head->next->data = stack->head->next->next->data; // 스택의 첫번째 노드의 데이터에 두번째 노드의 데이터 저장
    stack->head->next->next->data = tmp_data; // 스택의 두번째 노드의 데이터에 첫번째 노드의 데이터 저장
    tmp_rank = stack->head->next->rank;
    stack->head->next->rank = stack->head->next->next->rank;
    stack->head->next->next->rank = tmp_rank;
    write(1, "sb\n", 3);
    rst += 1;
}

// 기능 : 스택a와 스택b 둘다 취상위 2개 자리를 바꿈, 리턴: void
void            ss(t_list *stack_a, t_list *stack_b)
{
    int tmp_a_data;
    int tmp_b_data;
    int tmp_a_rank;
    int tmp_b_rank;

    if (stack_a->count < 2 || stack_b->count < 2)
        return ;
    tmp_a_data = stack_a->head->next->data; // tmp에 스택의 첫번째 노드의 데이터 저장
    stack_a->head->next->data = stack_a->head->next->next->data; // 스택의 첫번째 노드의 데이터에 두번째 노드의 데이터 저장
    stack_a->head->next->next->data = tmp_a_data; // 스택의 두번째 노드의 데이터에 첫번째 노드의 데이터 저장
    tmp_b_data = stack_b->head->next->data; // tmp에 스택의 첫번째 노드의 데이터 저장
    stack_b->head->next->data = stack_b->head->next->next->data; // 스택의 첫번째 노드의 데이터에 두번째 노드의 데이터 저장
    stack_b->head->next->next->data = tmp_a_data; // 스택의 두번째 노드의 데이터에 첫번째 노드의 데이터 저장
    tmp_a_rank = stack_a->head->next->rank;
    stack_a->head->next->rank = stack_a->head->next->next->rank;
    stack_a->head->next->next->rank = tmp_a_rank;
    tmp_b_rank = stack_b->head->next->rank;
    stack_b->head->next->rank = stack_b->head->next->next->rank;
    stack_b->head->next->next->rank = tmp_b_rank;
    write(1, "ss\n", 3);
    rst += 1;
}
