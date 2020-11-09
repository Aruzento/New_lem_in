# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erandal <erandal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/14 22:25:06 by erandal           #+#    #+#              #
#    Updated: 2020/11/09 17:46:37 by erandal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra
LIBRS = -lft -L $(LDIR)
INCS = -I $(IDIR) -I $(LHEAD)

LDIR = ./libft/
LHEAD = $(LDIR)includes/
LIBFT = $(LDIR)libft.a

ILIST = lemin.h\
	get_next_line.h
IDIR = ./includes/
IHEAD = $(addprefix $(IDIR), $(ILIST))

SDIR = ./srcs/
SLIST = ln_lemin.c			\
		get_next_line.c		\
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
SSRC = $(addprefix $(SDIR), $(SLIST))
SRCS = $(GSRC) $(SSRC)

ODIR = objs/
OSLST = $(patsubst %.c, %.o, $(SLIST))
OBJS = $(addprefix $(ODIR), $(OSLST))

# COLORS

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: print $(NAME)
	@echo "\n$(GREEN)Завершено успешно!$(RESET)"
	@echo "\nПроверить норму: make $(YELLOW)norme$(RESET)"
	@echo "\nТы так же можешь скачать карты и генератор!\n\tПросто напиши: make $(YELLOW)erandal$(RESET)"

print:
	@clear
	@echo "\n\tПодготовка к $(YELLOW)all$(RESET)"

dot:
	@echo "$(GREEN).$(RESET)\c"

$(NAME): $(LIBFT) $(ODIR) $(OBJS)
	@gcc $(FLAGS) $(LIBRS) $(INCS) $(OBJS) -o $(NAME)
	@echo "]\n-Создание $(GREEN)./$(NAME)$(RESET)"

$(LIBFT):
	@echo "-Создание $(GREEN)$(LIBFT)$(RESET)"
	@$(MAKE) -sC $(LDIR)

$(ODIR): 
	@mkdir -p $(ODIR)
	@echo "-Создание $(GREEN)object directory$(RESET)"
	@echo "-Создание $(GREEN)object files:$(RESET)"
	@echo "-Ожидайте [\c"

$(ODIR)%.o : $(SDIR)%.c $(IHEAD)
	@gcc $(FLAGS) -c $(INCS) $< -o $@ 
	@echo "$(GREEN)✓$(RESET)\c"

erandal:
	@rm -rf maps
	@git clone https://github.com/Aruzento/Maps.git maps
	@chmod 777 maps/generator
	@clear
	@echo "\n\t$(GREEN)Карты и генератор скачаны!$(RESET)"
	@echo "\nПапки: $(YELLOW)./non_valid$(RESET) и $(YELLOW)./valid$(RESET)\n\nЕсть стандартный генератор:"
	@echo " - '$(GREEN)--flow-one$(RESET)' - создает муравейник с уникальной тропой и $(YELLOW)1$(RESET) муравьем;"
	@echo " - '$(GREEN)--flow-ten$(RESET)' - создает муравейник с уникальной тропой и $(YELLOW)10$(RESET) муравьями;"
	@echo " - '$(GREEN)--flow-thousand$(RESET)' - создает муравейник с уникальной тропой и $(YELLOW)100$(RESET) муравьями;"
	@echo " - '$(GREEN)--big$(RESET)' - создает большую карту (примерно $(YELLOW)1000$(RESET) комнат) для проверки временной сложности;"
	@echo " - '$(GREEN)--big-superposition$(RESET)' - генерирует большую карту с пересекающимися путями;"
	@echo "\nПиши: './maps/generator $(GREEN)--Что-то$(RESET)'"

clean:
	@clear
	@echo "\n\tЧистим *.o..."
	@$(MAKE) -sC $(LDIR) clean
	@rm -rf $(ODIR)
	@clear
	@echo "\n\t$(GREEN)Все чисто!$(RESET)"

fclean: clean
	@echo "\n\tЧистим исполняющие файлы..."
	@rm -f $(LIBFT)
	@rm -rf maps
	@rm -f $(NAME)
	@clear
	@echo "\n\t$(GREEN)Все чисто!$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

norme :
	@norminette `find . -type f \( -name *.c -o -name *.h \)` \
	| if ! grep Error -B 1 --color; then echo "\tВсе файлы $(GREEN)по норме$(RESET)!"; fi