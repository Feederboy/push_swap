# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matt <maquentr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 13:16:34 by matt              #+#    #+#              #
#    Updated: 2022/03/14 12:40:46 by maquentr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC=gcc

OBJDIR = obj

CFLAGS=-g3 -Wall -Wextra -Werror -fsanitize=address

PATHS= $(OBJDIR)/srcs

SRC=main.c \
	parsing.c \
	set_stack.c \
	frees.c \
	setters_order.c \
	checkers_order.c \
	simple_sortings.c \
	operations1.c \
	operations2.c \
	rad_sort.c \
	box_sort.c \

INCFLAGS=-I.

LFLAGS= -Llib -lft

RM=rm -rf

INC=-I.

OBJ=$(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $@ $^ -Llibft/ -lft

$(OBJDIR) :
	mkdir $(OBJDIR) $(PATHS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJDIR)

re: fclean all

.PHONY: clean fclean
