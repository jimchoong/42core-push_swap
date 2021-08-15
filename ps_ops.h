#ifndef PS_OPS_H
# define PS_OPS_H
# include "pushswap.h"

// probably unnecessary

// structure to capture string cmd for pushswap
typedef struct s_op
{
	char		*op;
	struct s_op	*next;
}	t_op;

#endif
