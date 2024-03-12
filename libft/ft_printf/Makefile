# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 22:26:18 by flo-dolc          #+#    #+#              #
#    Updated: 2024/03/12 03:21:46 by flo-dolc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c \
				hex_utils.c \
				numbers_utils.c \
				pointer_utils.c \
				strings_utils.c

OBJS_DIR	=	obj/

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

NAME		=	libftprintf.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:			$(NAME)

$(OBJS_DIR):
				@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:	%.c | $(OBJS_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS_DIR) $(OBJS)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

clean:
				$(RM) $(OBJS)
				$(RM) -r $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

norm:
				@norminette $(SRCS)

.PHONY:			all bonus clean fclean re norm
