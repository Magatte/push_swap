# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pba <pba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/09 11:34:20 by pba               #+#    #+#              #
#    Updated: 2016/02/08 07:45:18 by pba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: mkdir_obj, clean, fclean, all

.SUFFIXES:

NAME		= push_swap
CFLAGS		= -Wall -Wextra -Werror -g
HPATH_FIL	= includes/
HPATH_LIBFT	= libft/includes/
SPATH		= src/
OPATH		= obj/

SRC			= push_swap.c \
			parser.c \
			list_manager.c \
			set_lists.c \
			set_opdata.c \
			set_positions.c \
			operations.c \
			sort_tab.c \
			is_sorted.c \
			push_sort.c \
			short_sort.c \
			display_op.c \
			display_stack.c

OBJ			= $(SRC:%.c=$(OPATH)%.o)

all: mkdir_obj $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;01mObject files created.\033[0m"
	@echo "\033[36;01mCompiling libft...\033[0m"
	@make re -C libft
	@echo "\033[32;01mlibft.a created.\033[0m"
	@gcc -o $(NAME) $(OBJ) -L./libft/ -lft
	@echo "\033[32;01mLink done.\033[0m"

$(OPATH)%.o: $(SPATH)%.c
	@gcc $(CFLAGS) -c $< -I $(HPATH_FIL) -I $(HPATH_LIBFT) -o $@

mkdir_obj:
	@mkdir -p $(OPATH)
	@echo "\033[32;01mobj/ folder created.\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "Objects deleted."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted."

re: fclean all
