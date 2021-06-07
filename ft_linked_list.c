#include "ft_push_swap.h"
#include <stdio.h>

// 기능: 새로운 노드 생성, 리턴: t_node
t_node			*new_node(int data)
{
	t_node *node;
	
	node = (t_node *)malloc(sizeof(t_node) * 1);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

// 기능: 리스트 초기화, 리턴: void
void			init_list(t_list *list)
{
	list->head = new_node(0);
	list->tail = new_node(0);
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->count = 0;
}

// 기능: 노드 추가, 리턴: void
void			add_node(t_list *list, int data)
{
	t_node *cur;

	cur = new_node(data);
	cur->prev = list->tail->prev;
	cur->next = list->tail;
	list->tail->prev->next = cur;
	list->tail->prev = cur;
	list->count++;
}

void			view_node(t_list *list)
{
	t_node *seek;

	seek = list->head->next;
	while (seek != list->tail)
	{
		printf("%d\n", seek->data);
		seek = seek->next;
	}
}