#include "ps_utils.h"
#include "libft.h"

int	rr(t_stacks *stacks)

{
	int	a;
	int	b;

	a = ra(stacks);
	if (!a)
		return (0);
	b = rb(stacks);
	if (!b)
		rra(stacks);
	return (a * b);
}

// add operation to string of operations done
int	add_op(t_stacks *stacks, char *op)
{
	char	*s;

	if (!stacks->ops)
	{
		s = ft_strdup(op);
		if (!s)
			return (0);
	}
	else
	{
		s = ft_strjoin(stacks->ops, op);
		if (!s)
			return (0);
		free(stacks->ops);
	}
	stacks->ops = s;
	return (1);
}
