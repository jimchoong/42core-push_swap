#include "ps_utils.h"

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
	int	a;
	int	b;

	a = sa(stacks);
	if (!a)
		return (0);
	b = sb(stacks);
	if (!b)
		sa(stacks);
	return (a * b);
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
