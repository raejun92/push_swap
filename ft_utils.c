#include "ft_push_swap.h"

static int		is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

// 기능: atoi 및 int형 범위에 있는지 확인, 리턴: int범위가 아니면 종료 맞으면 int형 숫자
int				ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (num * sign > 2147483647)
			error_msg();
		if (num * sign < -2147483648)
			error_msg();
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (sign * num);
}



// 기능: 오름차순인지 확인, 리턴: 맞으면 1, 아니면 0
int				check_ascending(t_list stack_a)
{
	int i;

	i = 0;
	while (i < stack_a.count - 1)
	{
		if (stack_a.head->next->data > stack_a.head->next->next->data)
			return (0);
		stack_a.head = stack_a.head->next;
		i++;
	}
	return (1);
}

void			set_sort(t_list *stack)
{
	t_node *tmp;

	tmp = stack->head->next;
	while (tmp != stack->tail)
	{
		if (tmp->sort == 0)
			tmp->sort = 1;
		tmp = tmp->next;
	}
}

// 기능: 스택에 정렬 안 된 노드의 개수 출력, 리턴: 정렬 안 된 노드 개수
int				out_of_alignment(t_list *stack)
{
	int		cnt;
	t_node	*tmp;

	cnt = 0;
	tmp = stack->head->next;
	while (tmp != stack->tail)
	{
		if (tmp->sort == 0)
			cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}