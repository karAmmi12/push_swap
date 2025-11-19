# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kammi <kammi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 16:46:02 by kammi             #+#    #+#              #
#    Updated: 2024/02/09 12:51:37 by kammi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##---------------------------------VARIABLES----------------------------------##
NAME = push_swap
ARCHIVE = push_swap.a
BONUS = checker
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MAKE_LIB = ar -rcs

##---------------------------------SOURCES------------------------------------##
SRCS = errors.c\
				ft_concatenate.c\
				ft_putstr_fd.c\
				ft_split.c\
				init_stack.c\
				main.c\
				push_b_a_utils.c\
				push.c\
				reverse_rotate.c\
				rotate.c\
				sort.c\
				stack_utils.c\
				swap.c\
				update.c\


##---------------------------------OBJECTS------------------------------------##
OBJS = $(SRCS:.c=.o)

##---------------------------------CHECKER------------------------------------##
CHECKER_DIR = bonus
CHECKER_PATH = $(CHECKER_DIR)/$(BONUS)
CHECKER_SRCS = checker_bonus.c\
								errors_bonus.c\
								ft_concatenate_bonus.c\
								ft_putstr_fd_bonus.c\
								init_stack_bonus.c\
								push_bonus.c\
								reverse_rotate_bonus.c\
								rotate_bonus.c\
								stack_utils_bonus.c\
								swap_bonus.c\
								get_next_line_bonus.c\
								get_next_line_utils_bonus.c\
								ft_split_bonus.c\

CHECKER_OBJS = $(CHECKER_SRCS:%.c=$(CHECKER_DIR)/%.o)

##---------------------------------RULES--------------------------------------##
all: $(NAME) $(ARCHIVE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(ARCHIVE): $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

$(BONUS) : $(CHECKER_OBJS) $(NAME)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(BONUS)

clean:
	$(RM) $(OBJS) $(ARCHIVE)
	$(RM) $(CHECKER_OBJS)

fclean: clean
	$(RM) $(NAME) $(ARCHIVE)
	$(RM) $(BONUS)

re: fclean all

bonus : $(BONUS)

.PHONY: all clean fclean re bonus


