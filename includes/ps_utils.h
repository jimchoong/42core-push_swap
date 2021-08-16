#ifndef PS_UTILS_H
# define PS_UTILS_H
# include <limits.h>
# include "libft.h"
# include "pushswap.h"
# include <stdlib.h>
# define WIDTH 11

int			verify_input(int argc, char *argv[]);
t_stack_e	*new_e(int val);
t_stacks	*init_stacks(int argc, char *argv[]);
void		append_back(t_stack_h *head, t_stack_e *new);
void		free_stacks(t_stacks *stacks);
void		print_stacks(t_stacks *stacks);
void		print_ops(t_stacks *stacks);
#endif