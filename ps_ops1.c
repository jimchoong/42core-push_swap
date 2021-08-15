#include "pushswap.h"

// add operation to string of operations done
int	add_op(t_stacks *stacks, char *op)
{
	char	*s;

	if (!stacks->op)
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

int	sa(t_stacks *stacks)
{
	int	tmp;

	if (!stacks->a->top || !stacks->a->top->next)
		return (0);
	tmp = stacks->a->top->val;
	stacks->a->top->val = stacks->a->top->next->val;
	stacks->a->top->next->val = tmp;
	return (1);
}

int	sb(t_stacks *stacks)
{
	int	tmp;

	if (!stacks->b->top || !stacks->b->top->next)
		return (0);
	tmp = stacks->b->top->val;
	stacks->b->top->val = stacks->b->top->next->val;
	stacks->b->top->next->val = tmp;
	return (1);
}

int	ss(t_stacks *stacks)
{
	int	sa;
	int	sb;

	sa = sa(stacks);
	if (!sa)
		return (0);
	sb = sb(stacks);
	if (!sb)
		sa(stacks);
	return (sa * sb);
}

int	pa(t_stacks *stacks)
{
	t_stack_e	*tmp_b;

	if (!stacks->b->top)
		return (0);
	tmp_b = stacks->b->top;
	stacks->b->top = tmp_b->next;
	if (!stacks->b->top)
		stacks->b->btm = NULL;
	tmp_b->next = stacks->a->top;
	if (!stacks->a->top)
		stacks->a->btm = tmp_b;
	stacks->a->top = tmp_b;
	return (1);
}

int	pb(t_stacks *stacks)
{
	t_stack_e	*tmp_a;

	if (!stacks->a->top)
		return (0);
	tmp_a = stacks->a->top;
	stacks->a->top = tmp_a->next;
	if (!stacks->a->top)
		stacks->a->btm = NULL;
	tmp_a->next = stacks->b->top;
	if (!stacks->b->top)
		stacks->b->btm = tmp_a;
	stacks->b->top = tmp_a;
	return (1);
}

int	ra(t_stacks *stacks)
{
	t_stack_e	*tmp;

	if (!stacks->a->top)
		return (0);
	if (stacks->a->top == stacks->a->btm)
		return (0);
	tmp = stacks->a->top;
	stacks->a->top = tmp->next;
	stacks->a->btm->next = tmp;
	stacks->a->btm = tmp;
	tmp->next = NULL;
	return (1);
}

int	rb(t_stacks *stacks)
{
	t_stack_e	*tmp;

	if (!stacks->b->top)
		return (0);
	if (stacks->b->top == stacks->b->btm)
		return (0);
	tmp = stacks->b->top;
	stacks->b->top = tmp->next;
	stacks->b->btm->next = tmp;
	stacks->b->btm = tmp;
	tmp->next = NULL;
	return (1);
}

int	rra(t_stacks *stacks)
{
	t_stack_e	*tmp;
	t_stack_e	*trav;

	if (!stacks->a->top)
		return (0);
	if (stacks->a->top == stacks->a->btm)
		return (0);
	tmp = stacks->a->btm;
	trav = stacks->a->top->next;
	if (trav == tmp)
		return (sa(stacks));
	while (trav)
	{
		if (trav->next == tmp)
			break ;
		trav = trav->next;
	}
	trav->next = NULL;
	tmp->next = stacks->a->top;
	stacks->a->top = tmp;
	stacks->a->btm = trav;
	return (1);
}

int	rrb(t_stacks *stacks)
{
	t_stack_e	*tmp;
	t_stack_e	*trav;

	if (!stacks->b->top)
		return (0);
	if (stacks->b->top == stacks->b->btm)
		return (0);
	tmp = stacks->b->btm;
	trav = stacks->b->top->next;
	if (trav == tmp)
		return (sb(stacks));
	while (trav)
	{
		if (trav->next == tmp)
			break ;
		trav = trav->next;
	}
	trav->next = NULL;
	tmp->next = stacks->b->top;
	stacks->b->top = tmp;
	stacks->b->btm = trav;
	return (1);
}

int	rrr(t_stacks *stacks)
{
	int	rra;
	int	rrb;

	rra = rra(stacks);
	if (!rra)
		return (0);
	rrb = rrb(stacks);
	if (!rrb)
		ra(stacks);
	return (rra * rrb);
}

int	rr(t_stacks *stacks)
{
	int	ra;
	int	rb;

	ra = ra(stacks);
	if (!ra)
		return (0);
	rb = rb(stacks);
	if (!rb)
		rra(stacks);
	return (ra * rb);
}
