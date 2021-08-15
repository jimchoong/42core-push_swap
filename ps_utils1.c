#include "ps_utils.h"
#include "pushswap.h"

static int	verify_unique(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < argc)
	{
		j = i + 1;
		while (j < argc)
			if (ft_strcmp(argv[i], argv[j++]) == 0)
				return (0);
		i++;
	}
	return (1);
}

static int	verify_num(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	verify_size(int argc, char *argv[])
{
	int		i;
	long	num;

	i = 0;
	while (i < argc)
	{
		num = ft_atoi(argv[i++]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
	}
	return (1);
}

/* 
*	verify_input:	check if input args are integers, unique
*					and within limits of int
*	params:		argc length, argv char array
*	returns:	1 if valid,
*				0 if invalid
*/
int	verify_input(int argc, char *argv[])
{
	return (verify_num(argc, argv) && \
			verify_unique(argc, argv) && \
			verify_size(argc, argv));
}

void	print_stacks(t_stacks *stacks)
{
	int			i;
	t_stack_e	*a;
	t_stack_e	*b;

	i = 0;
	a = stacks->a->top;
	b = stacks->b->top;
	ft_printf("A \t B\n");
	while (i++ < stacks->stack_len && a && b)
	{
		ft_printf("%i \t %i\n", a->val, b->val);
		a = a->next;
		b = b->next;
	}
	ft_printf("==================\n");
}
