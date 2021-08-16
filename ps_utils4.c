#include "pushswap.h"
#include "ps_utils.h"
#include "ft_printf.h"

void	print_ops(t_stacks *stacks)
{
	ft_printf("%s", stacks->ops);
}

static int	count_digits(int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		num *= -1;
	}
	if (num == 0)
		count++;
	else
	{
		while (num)
		{
			count++;
			num /= 10;
		}
	}
	return (count);
}

static void	print_pad(int i)
{
	if (i < WIDTH)
		while (++i < WIDTH)
			write(1, " ", sizeof(char));
}

static void	print_num(int num)
{
	int		i;
	char	*pad;

	i = count_digits(num);
	ft_printf("%d", num);
	print_pad(i);
}

/*
*	print_stacks_h: print out numbers in stack A & B
*	params: t_stacks data
*	return: none
*/
void	print_stacks(t_stacks *stacks)
{
	t_stack_e	*a;
	t_stack_e	*b;

	a = stacks->a->top;
	b = stacks->b->top;
	ft_printf("A          \tB          \n");
	while (a || b)
	{
		if (a)
		{
			print_num(a->val);
			a = a->next;
		}
		else
			print_pad(0);
		ft_printf("\t");
		if (b)
		{
			print_num(b->val);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("==========================\n");
}
