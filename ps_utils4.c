#include "pushswap.h"
#include <stdio.h>

void	print_ops(t_stacks *stacks)
{
	ft_printf("%s", stacks->ops);
}

/*
*	print_stacks_h: print out numbers in stack A & B
*	params: t_stacks data
*	return: none
*	Notes:	1. Printing stacks horizontally due to my printf fn not having 
*			width flag, which will cause alignment issues
*			2. Not suitable for long stacks as horizontal length may
*			exceed screen width, causing viewing issues
*/
static void	print_stacks_h(t_stacks *stacks)
{
	t_stack_e	*a;
	t_stack_e	*b;

	a = stacks->a->top;
	b = stacks->b->top;
	ft_printf("A | ");
	while (a)
	{
		ft_printf("%i ", a->val);
		a = a->next;
	}
	ft_printf("\nB | ");
	while (b)
	{
		ft_printf("%i ", b->val);	
		b = b->next;
	}
	ft_printf("\n======================================\n");
}

/*
*	print_stacks_h: print out numbers in stack A & B
*	params: t_stacks data
*	return: none
*	Notes:	1. Uses printf instead as my ft_printf does not have width flag
*			to maintain alignment of printed stacks
*/
void	print_stacks(t_stacks *stacks)
{
	int			i;
	t_stack_e	*a;
	t_stack_e	*b;

	i = 0;
	a = stacks->a->top;
	b = stacks->b->top;
	printf("%-10c\t%-10c\n", 'A', 'B');
	while (i++ < stacks->stack_len && a && b)
	{
		printf("%-10i\t%-10i\n", a->val, b->val);
		a = a->next;
		b = b->next;
	}
	printf("==================\n");
}
