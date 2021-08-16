SRCS	=	$(wildcard srcs/*.c)
OBJS	=	${SRCS:.c=.o}
NAME	=	libft.a
CFLAGS	=	-Wall -Wextra -Werror
INC_DIR =	includes

.c.o:
			gcc ${CFLAGS} -c -I$(INC_DIR) $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re