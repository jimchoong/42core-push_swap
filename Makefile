NAME1	=	push_swap
NAME2	=	checker
SRCS1	=	*.c
CC		=	gcc
CCFLAGS	=	-Wall -Werror -Wextra
OBJS1	=	$(SRCS1:.c=.o)
HEADER	= 	-I ./includes -I ./libft/includes
LIB		=	-L ./libft -l ft

%.o: %.c
			$(CC) $(CFLAGS) -c $(HEADER) -O3 $< -o $(<:.c=.o)

all: 		$(NAME1)

libft:
			make -C ./libft

clean_libft:
			make clean -C ./libft

$(NAME1):	libft $(OBJS1) 
			$(CC) $(CCFLAGS) -o $(NAME1) $(OBJS1) $(LIB)

clean:		clean_libft
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME) ./libft/libft.a

re:			fclean all

.PHONY:		maall clean fclean re libft clean_libft