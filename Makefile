NAME		=	push_swap

SRCS		=	create_node.c \
				ft_atoi_int.c \
				list_headtail.c \
				main.c \
				push_swap.c \
				sort_check.c \
				sort_nano_a.c \
				sort_nano_b.c \
				sort_six_over.c \
				swap_a.c \
				swap_b.c \
				swap_pa_ra.c \
				swap_papb.c \
				tmp.c \
				useful_functions.c \
				writing_swap.c \
				
OBJS		=	$(SRCS:.c=.o)

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:		
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)        

.PHONY:			all clean fclean re
