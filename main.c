#include "pushswap.h"
#include "libft.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	t_ops		*ops;

	if (argc < 2)
		error();
	stacks = init_stacks(--argc, ++argv);
	if (!ops || !stacks)
	{
		free_stacks(stacks);
		error();
	}
	push_swap(stacks);
	free_stacks(stacks);
	return (0);
}
