#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_node
{
	struct		s_node *next;
	struct		s_node *prev;
	int			data;
}				t_node;

typedef struct	s_list
{
	t_node		*head;
	t_node		*tail;
	int			count;
}				t_list;

/* ft_utils.c */
int				ft_isdigit(int c);
int				ft_atoi(const char *str);

/* ft_utils2.c */
char			**free_malloc(char **str);
char			**ft_split(char const *s, char c);

/* ft_linked_list.c */
t_node			*new_node(int data);
void			init_list(t_list *list);
#endif