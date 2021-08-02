#include "ft_push_swap.h"

// 기능: 노드의 데이터를 배열에 넣음, 리턴: void
static void		input_array(t_list stack_a, int *sorted_node)
{
	t_node *tmp;

	tmp = stack_a.head->next;
	while (tmp != stack_a.tail)
	{
		*sorted_node = tmp->data;
		tmp = tmp->next;
		sorted_node++;
	}
}

// 기능: 노드를 배열로 오름차순 정렬 및 중복 검사, 리턴: void
static void		sort_ascending(int *sorted_node, int size)
{
	int i;
	int j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (sorted_node[j] == sorted_node[j + 1]) // 중복 검사
				error_msg();
			if (sorted_node[j] > sorted_node[j + 1])
			{
				tmp = sorted_node[j];
				sorted_node[j] = sorted_node[j + 1];
				sorted_node[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

// 기능: 노드를 미리 정렬시켜 놓은 배열을 만들어 이용할 예정, 리턴: void
void			make_sorted_array(t_list stack_a, int *sorted_node)
{
	input_array(stack_a, sorted_node); // 노드 데이터를 배열에 넣기
	sort_ascending(sorted_node, stack_a.count); // 오름차순 정렬 및 중복 확인
}