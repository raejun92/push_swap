#include "ft_push_swap.h"

// 기능: 인수가 문자형태인 숫자로 들어왔는지 확인, 리턴: 맞으면 1 아니면 0
int			check_text_numeric(char *param)
{
	// 인수에 ''이나 ""이 들어올때 안 걸러짐
	if (!param)
		return (0);
	while (*param)
	{
		// 숫자인지 확인
		if (!(ft_isdigit(*param)))
			return(0);
		param++;
	}
	return (1);
}

// 기능: 들어온 인수가 조건에 맞게 들어온 것인지 확인, 리턴: 맞으면 노드에 인수 추가 틀리면 종료
void			check_input(char *param, t_list *stack_a)
{
	char	**str;
	
	while (*param)
	{
		str = ft_split(param, ' ');
	if (!(check_text_numeric(param))) // 인수가 숫자인지 확인
		exit (0);
	add_node(stack_a, ft_atoi(*str)); // 인수를 스택a에 추가
		param++;
	}
	free_malloc(str);
}

int			main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;

	if (argc < 3)
		return (0);
	init_list(&stack_a);
	init_list(&stack_b);
	while (*(++argv))
		check_input(*argv, &stack_a);
	view_node(&stack_a);
	printf("\n");
	add_node(&stack_b, 10);
	add_node(&stack_b, 5);
	add_node(&stack_b, 29);
	view_node(&stack_b);
	printf("\n");
	rrr(&stack_a, &stack_b);
	view_node(&stack_a);
	printf("\n");
	view_node(&stack_b);
	return (0);
}
