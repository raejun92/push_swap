#include <stdio.h>

typedef struct	s_node
{
	int			data;
}				t_node;

typedef struct	s_list
{
	t_node		*head;
}				t_list;


void move(t_list list)
{
	t_node b;
	
	b.data = 11;
	list.head = &b;
	printf("move %p\n", list.head);
}

void move2(t_list *list)
{
	t_node c;

	c.data = 33;
	list->head = &c;
	printf("move2 %d\n", list->head->data);
}

int main()
{
	t_list list;
	t_node a;
	
	a.data = 44;
	list.head = &a;

	printf("main %p\n", list.head);
	move(list);
	printf("%d\n", list.head->data);
	move2(&list);
	printf("%d\n", list.head->data);
}