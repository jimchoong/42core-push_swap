#include "ps_utils.h"

static t_stack_e	*new_e(int val)
{
	t_stack_e	*el;

	el = malloc(sizeof(t_stack_e));
	if (!el)
		return (NULL);
	el->val = val;
	el->next = NULL;
	return (el);
}

static t_stack_h	*new_h(void)
{
	t_stack_h	*head;

	head = malloc(sizeof(t_stack_h));
	if (!head)
		return (NULL);
	head->top = NULL;
	head->btm = NULL;
	head->is_sorted = 0;
	head->median = 0;
	head->len = 0;
	return (head);
}

static void	append_back(t_stack_h *head, t_stack_e *new)
{
	t_stack_e	*tmp;

	if (!head->top)
	{
		head->top = new;
		head->btm = new;
	}
	else
	{
		tmp = head->top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		head->btm = new;
	}
}

static int	make_stacks(t_stacks *stacks, char *argv[])
{
	int			i;
	t_stack_e	*el;

	i = 0;
	while (i < stacks->stack_len)
	{
		el = new_e(ft_atoi(argv[i++]));
		if (!el)
			return (0);
		append_back(stacks->a, el);
	}
	return (1);
}

t_stacks	*init_stacks(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (!verify_input(argc, argv))
		return (NULL);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = new_h();
	stacks->b = new_h();
	if (!stacks->a || !stacks->b)
	{
		free_stacks(stacks);
		return (NULL);
	}
	stacks->stack_len = argc;
	stacks->ops = NULL;
	if (!make_stacks(stacks, argv))
	{
		free_stacks(stacks);
		return (NULL);
	}
	return (stacks);
}
