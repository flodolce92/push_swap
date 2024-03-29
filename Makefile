# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 11:19:31 by flo-dolc          #+#    #+#              #
#    Updated: 2024/03/28 16:44:14 by flo-dolc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	src/

SRC			=	check_args.c \
				check_args_utils.c \
				frees.c \
				list_utils.c \
				push_swap.c \
				push_swap_utils.c \
				push.c \
				swap.c \
				rotate.c \
				reverse_rotate.c \
				sort_utils.c \

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR	=	obj/

OBJS		=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

NAME		=	push_swap

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

INCLUDES	=	-Ilibft

LIBFT_FLAGS	=	-Llibft -lft

all:			$(NAME)

$(OBJS_DIR):
				@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c | $(OBJS_DIR)
				$(CC) $(CFLAGS) -g -c $< -o $@ $(INCLUDES)

$(NAME):		$(OBJS_DIR) $(OBJS)
				@make -C ./libft
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS)

clean:
				$(RM) $(OBJS)
#@make -C ./libft clean

fclean:			clean
				$(RM) $(NAME)
				$(RM) -r $(OBJS_DIR)
#@make -C ./libft fclean

re:				fclean all

test:			all
				./push_swap 3 2 1 0

norm:
				@norminette $(SRCS) $(SRCS_DIR)push_swap.h

.PHONY:			all clean fclean re norm test
