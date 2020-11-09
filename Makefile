# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erandal <erandal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/14 22:25:06 by erandal           #+#    #+#              #
#    Updated: 2020/11/09 15:23:26 by erandal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCDIR = srcs				#											#
LDIR = libft				#		Различные директории, сделал		#
INCDIR = includes			#			просто для красоты				#
GNLDIR = gnl				#			  и все, серьезно				#
ODIR = objs					#											#

SRC = 	ln_lemin.c			\
		ln_initialization.c	\
		ln_utils.c			\
		ln_rooms_utils.c	\
		ln_get_ants.c		\
		ln_get_rooms.c		\
		ln_get_links.c		\
		ln_bfs.c 			\
		ln_choosing_path.c	\
		ln_print_result.c	\
		ln_print_alt.c		\
		ln_exit_prg.c

GNL = get_next_line.c

INC =	-I ./includes/			\
		-I ./gnl/				\
		-I ./libft/includes/	\

FLAGS = -c -Wall -Wextra -Werror

SRCS =	$(addprefix ./srcs/, $(SRC))	\
		$(addprefix ./gnl/, $(GNL))			

OBJS =	$(SRC:.c=.o)	\
		$(GNL:.c=.o)

LIBFT = $(addprefix ./libft/, libft.a)

.PHONY: clean fclean all re

all: $(NAME)

$(LIBFT):
	@make -C libft > tmp.log

$(NAME): $(LIBFT)
	@gcc $(FLAGS) $(SRCS) $(INC) -g
	@gcc -o $(NAME) $(OBJS) -L libft/ -lft $(INC) -g

pack:
	@mkdir objs >> tmp.log
	@mv *.o objs >> tmp.log

clean:
	@clear
	@rm -rf $(ODIR) >> tmp.log
	@rm -rf $(OBJS) >> tmp.log
	@#make -C libft/ clean >> tmp.log

fclean: clean
	@rm -rf $(NAME) >> tmp.log
	@make -C libft/ fclean >> tmp.log
	@rm -rf tmp.log

re: fclean all
