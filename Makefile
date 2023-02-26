# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 11:33:04 by amugnier          #+#    #+#              #
#    Updated: 2023/02/26 11:42:53 by amugnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PATH_LIBFT = libft
LIBFT = $(PATH_LIBFT)/libft.a

PATH_SRCS = srcs

SRCS = $(PATH_SRCS)/main.c \
		 $(PATH_SRCS)/init.c \
		 $(PATH_SRCS)/stack.c \
		 $(PATH_SRCS)/push_stack.c \
		 $(PATH_SRCS)/swap_position.c \
		 $(PATH_SRCS)/rotate_position.c \
		 $(PATH_SRCS)/reverse_rotate_position.c \
		 $(PATH_SRCS)/push_swap.c \
		 $(PATH_SRCS)/algo.c \
		 $(PATH_SRCS)/count.c \
		 $(PATH_SRCS)/movement.c \
		 $(PATH_SRCS)/position.c \
		 $(PATH_SRCS)/end.c \
		 $(PATH_SRCS)/utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(PATH_LIBFT) -I $(PATH_SRCS)

$(LIBFT):
	$(MAKE) -C $(PATH_LIBFT)

clean:
	$(MAKE) -C $(PATH_LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(PATH_LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
