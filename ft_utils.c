#include "ft_push_swap.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

// 기능: atoi 및 int형 범위에 있는지 확인, 리턴: int범위가 아니면 종료 맞으면 int형 숫자
int			ft_atoi(const char *str)
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

void		error_msg()
{
	write(1, "Error", 5);
	write(1, "\n", 1);
	exit(0);
}

int			intlen(int *num)
{
	int i;

	i = 0;
	while (num[i])
		i++;
	return (i);
}