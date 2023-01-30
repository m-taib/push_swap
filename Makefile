# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 15:11:45 by mtaib             #+#    #+#              #
#    Updated: 2023/01/29 17:17:45 by mtaib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c

OSRC = $(SRC:.c=.o)

CMN = ft_lstnew.c instructions_functions.c check_errors.c check_errors2.c linked_list_utils.c \
	  push_swap_utils.c sort_utils.c sort_5_elements.c push_swap_utils2.c

BSRC = checker.c
BOBJ = $(BSRC:.c=.o)
OCMN = $(CMN:.c=.o)

NAME = push_swap
CHECKER = checker
CFLAGS = -Wextra -Werror -Wall

%.o:%.c
	cc -c $(CFLAGS) $<

all: $(NAME)

$(NAME) :$(OSRC) $(OCMN)
		cc $(CFLAGS) $^ -o $(NAME)
	
bonus : $(CHECKER)

$(CHECKER) :$(BOBJ) $(OCMN)
		cc $(CFLAGS) $^ -o checker
clean :
	@rm -f *.o
fclean : 
	@rm -f *.o $(NAME) $(CHECK)
re : fclean all

.PHONY : all clean fclean re bonus
