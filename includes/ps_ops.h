#ifndef PS_OPS_H
# define PS_OPS_H
# include "pushswap.h"

// structure to capture string cmd for pushswap
typedef struct s_op
{
	char		*op;
	struct s_op	*next;
}	t_op;

int	add_op(t_stacks *stacks, char *op);
int	sa(t_stacks *stacks);
int	sb(t_stacks *stacks);
int	ss(t_stacks *stacks);
int	pa(t_stacks *stacks);
int	pb(t_stacks *stacks);
int	ra(t_stacks *stacks);
int	rb(t_stacks *stacks);
int	rra(t_stacks *stacks);
int	rrb(t_stacks *stacks);
int	rrr(t_stacks *stacks);
int	rr(t_stacks *stacks);

#endif
