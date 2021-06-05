#include "ft_push_swap.h"
#include <stdio.h>

// 기능: a의 맨 위 2소요 위치 변경, 리턴: void
// void		ft_sa(t_stack *stack)
// {
	
// }

// 기능: 인수가 문자형태인 숫자로 들어왔는지 확인, 리턴: 맞게 들어왔으면 1 아니면 0
int			check_input(char *param)
{
	// 인수에 ''이나 ""이 올때 안 걸러짐
	if (!param)
		return (0);
	while (*param)
	{
		if (!(ft_isdigit(*param)))
			return(0);
		param++;
	}
	return (1);
}

// 기능: int형 인수가 int 범위에 속하는지 검사
/* int			check_number_range()
{

} */

int			main(int argc, char **argv)
{
	t_stack stack;
	int check;

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
