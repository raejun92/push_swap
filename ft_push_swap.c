#include "ft_push_swap.h"
#include <stdio.h>

// 기능: a의 맨 위 2소요 위치 변경, 리턴: void
// void		ft_sa(t_stack *stack)
// {
	
// }

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

// 기능: 들어온 인수가 조건에 맞게 들어온 것인지 확인, 리턴: 맞으면 인수 출력 틀리면 종료
int			check_input(char *param)
{
	int	tmp;

	if (!(check_text_numeric(param))) // 인수가 숫자인지 확인
		exit (0);
	// stack_a->tail->data = ft_atoi(param);
	tmp = ft_atoi(param);
	if (!(tmp))
		exit (0);
	return (tmp);
}

int			main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	int		check;

	if (argc < 3)
		return (0);
	
	while (*(++argv))
	{
		printf("|%s|\n", *argv);
		check = check_input(*argv);
		printf("%d\n", check);
	}
	
	//ft_sa(&stack);
	return (0);
}
