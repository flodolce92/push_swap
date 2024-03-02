# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 11:19:31 by flo-dolc          #+#    #+#              #
#    Updated: 2024/03/02 12:22:44 by flo-dolc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	src/

SRC			=	push_swap.c \
				check_args.c \
				frees.c \

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
				mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c | $(OBJS_DIR)
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

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

norm:
				@norminette $(SRCS)

.PHONY:			all clean fclean re norm
