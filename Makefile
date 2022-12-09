# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 11:33:04 by amugnier          #+#    #+#              #
#    Updated: 2022/12/09 11:33:22 by amugnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror

PATH_LIBFT = libft/
PATH_SRCS = srcs/


LIBFT = $(PATH_LIBFT)libft.a

SRCS_P = $(PATH_SRCS)main.c

SRCS = $(SRCS_P)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(PATH_LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C $(PATH_LIBFT)
	@rm -f $(OBJS)

fclean: clean

	@make fclean -C $(PATH_LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
