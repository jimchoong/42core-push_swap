#include "libft.h"
#include "ps_utils.h"

static void	free_stack(t_stack_h *head)
{
	t_stack_e	*tmp;

	if (head->top)
	{
		tmp = head->top->next;
		while (tmp)
		{
			free(head->top);
			head->top = tmp;
			if (tmp)
				tmp = head->top->next;
		}
		free(head->top);
	}
	free(head);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->a)
			free_stack(stacks->a);
		if (stacks->b)
			free_stack(stacks->b);
		if (stacks->ops)
			free(stacks->ops);
	}
	free(stacks);
}
