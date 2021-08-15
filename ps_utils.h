#ifndef PS_UTILS_H
# define PS_UTILS_H
# include <limits.h>
# include "libft/libft.h"
# include "pushswap.h"
# include <stdlib.h>

int			verify_input(int argc, char *argv[]);
void		print_stacks(t_stacks *stacks);
t_stacks	*init_stacks(int argc, char *argv[]);
void		free_stacks(t_stacks *stacks);
#endif