# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erandal <erandal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/14 22:25:06 by erandal           #+#    #+#              #
#    Updated: 2020/11/04 17:39:29 by erandal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCDIR = srcs				#											#
LDIR = libft				#		Различные директории, сделал		#
INCDIR = includes			#			просто для красоты				#
GNLDIR = gnl				#			  и все, серьезно				#
ODIR = objs					#											#

SRC = 	lemin.c			\
		exit_prg.c			\
		get_ants.c			\
		get_rooms.c			\
		get_links.c			\
		bfs.c 				\
		key_create.c		\
		read_root.c 		\
		chose_way.c 		\
		print.c

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
