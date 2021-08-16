#include "ps_utils.h"

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
	int	a;
	int	b;

	a = rra(stacks);
	if (!a)
		return (0);
	b = rrb(stacks);
	if (!b)
		ra(stacks);
	return (a * b);
}
