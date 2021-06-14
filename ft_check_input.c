#include "ft_push_swap.h"

static int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


// 기능: 인수가 문자형태인 숫자로 들어왔는지 확인, 리턴: 맞으면 1 아니면 0
static int      check_text_numeric(char *param)
{
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

// 기능: 들어온 인수가 조건에 맞게 들어온 것인지 확인, 리턴: 맞으면 스택에 노드 추가 틀리면 종료
void			check_input(char *param, t_list *stack_a)
{
	if (!(check_text_numeric(param))) // 인수가 숫자인지 확인
		error_msg();
	add_node(stack_a, ft_atoi(param)); // 인수를 스택a에 추가
}