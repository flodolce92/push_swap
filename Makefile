# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 11:19:31 by flo-dolc          #+#    #+#              #
#    Updated: 2024/04/08 22:08:22 by flo-dolc         ###   ########.fr        #
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
				quick_sort.c \
				swap.c \
				rotate.c \
				reverse_rotate.c \
				sort_few_utils.c \
				sort_more_utils.c

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
				@make -C ./libft clean

fclean:			clean
				$(RM) $(NAME)
				$(RM) -r $(OBJS_DIR)
				@make -C ./libft fclean

re:				fclean all

test:			all
				@ARG="467 248 217 -18 383 -349 73 -315 -140 264 -162 -408 446 391 464 374 83 75 35 -303 -294 378 -487 198 349 79 -230 -234 227 288 -115 275 -45 362 -277 -58 -305 407 381 453 251 -54 -355 -200 -202 138 -44 332 424 -37 347 13 -291 183 -464 -172 -273 -141 -499 -153 -242 415 -127 480 -221 187 370 -429 379 -154 -354 107 317 -414 479 -203 22 -167 -87 143 -61 130 86 -473 -358 -99 373 221 360 257 -427 -266 44 7 28 223 6 60 234 423"; ./push_swap $$ARG

checker:		all
				@ARG="467 248 217 -18 383 -349 73 -315 -140 264 -162 -408 446 391 464 374 83 75 35 -303 -294 378 -487 198 349 79 -230 -234 227 288 -115 275 -45 362 -277 -58 -305 407 381 453 251 -54 -355 -200 -202 138 -44 332 424 -37 347 13 -291 183 -464 -172 -273 -141 -499 -153 -242 415 -127 480 -221 187 370 -429 379 -154 -354 107 317 -414 479 -203 22 -167 -87 143 -61 130 86 -473 -358 -99 373 221 360 257 -427 -266 44 7 28 223 6 60 234 423"; ./push_swap $$ARG | ./checker_linux $$ARG

norm:
				@norminette $(SRCS) $(SRCS_DIR)push_swap.h

.PHONY:			all clean fclean re norm test checker
