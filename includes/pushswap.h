#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>

// structure for stack element
typedef struct s_stack_e
{
	struct s_stack_e	*next;
	int					val;
}	t_stack_e;

// structure for stack header
typedef struct s_stack_h
{
	struct s_stack_e	*top;
	struct s_stack_e	*btm;
	int					is_sorted;
	int					median;
	int					len;
}	t_stack_h;

// structure for 2 stacks, a & b
typedef struct s_stacks
{
	struct s_stack_h	*a;
	struct s_stack_h	*b;
	int					stack_len;
	char				*ops;
}	t_stacks;


#endif
