SRC = ft_lstnew.c push_swap.c instructions_functions.c check_errors.c check_errors2.c
OBJ = ft_lstnew.o push_swap.o instructions_functions.o check_errors.o check_errors2.o
NAME = push_swap
all: $(NAME)
$(NAME): $(OBJ)
	gcc -Wextra -Werror -Wall $^ -o push_swap
fclean : 
		@rm -f *.o $(NAME)
re : fclean all
