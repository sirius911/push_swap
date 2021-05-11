# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 15:21:30 by clorin            #+#    #+#              #
#    Updated: 2021/05/10 15:21:34 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PSW 	= push_swap
CHECKER = checker

CC		= clang

FLAGS	= -Wall -Werror -Wextra

HEADER	= -I includes/

SRCS_CHECKER = srcs/checker.c

SRCS_PSW = srcs/push_swap.c

OBJ_CHECKER		= $(SRCS_CHECKER:.c=.o)

OBJ_PSW			= $(SRCS_PSW:.c=.o)

all :	$(PSW) $(CHECKER)

.c.o :	
		@printf "\033[0;33mGenerating objects... %-33.33s\r" $@
		@$(CC) $(FLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(CHECKER) :	$(OBJ_CHECKER)
				@make -C libft/
				@$(CC) $(FLAGS) $(HEADER) $(OBJ_CHECKER) -o $(CHECKER) -L libft/ -lft
				@echo "Building checker : \033[32mOK\033[0m"

$(PSW) :		$(OBJ_PSW)
				@make -C libft/
				@$(CC) $(FLAGS) $(HEADER) $(OBJ_PSW) -o $(PSW) -L libft/ -lft
				@echo "Building push_swap : \033[32mOK\033[0m"

clean :		
		@rm -rf $(OBJ_CHECKER) $(OBJ_PSW)
		@echo "Delete OBJ files : \033[32mOK\033[0m"

fclean :	clean
		@make fclean -C libft/
		@rm -rf $(PSW)
		@rm -rf $(CHECKER)
		@echo "Delete push_swap and checker : \033[32mOK\033[0m"

re :	fclean all

.PHOMY :	all clean fclean re
