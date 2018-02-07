# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acottier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 13:55:41 by acottier          #+#    #+#              #
#    Updated: 2016/09/21 13:18:41 by acottier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				=	\033[31m
GREEN			=	\033[32m
YELLOW			=	\033[33m
NC				=	\033[0m

NAME			=	ft_select

SRC_NAMES		=	main.c \
					mklist.c \
					disp_settings.c \
					init.c \
					error.c \
					display_elems.c \
					shell_modify.c \
					commands.c \
					utilities.c \
					select_utilities.c \
					modular_selection.c \
					sig_handler.c \
					search.c

OBJ_NAMES 		=	$(SRC_NAMES:.c=.o)
INC_NAMES		=	libft.h
LIB_NAMES		=	libft.a

SRC_PATH		=	./sources
OBJ_PATH		=	./objects
INC_PATH		=	./include ./libfts
LIB_PATH		=	./libft/

SRC 			=	$(addprefix $(SRC_PATH)/,$(SRC_NAMES))
OBJ				=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAMES))
INC				=	$(addprefix -I,$(INC_PATH))
LIB				=	$(LIB_PATH)$(LIB_NAMES)

FLAGS			=	-g3 -Wall -Wextra -Werror
LDLIBS			=	-lft

all : $(LIB) $(NAME)

$(NAME): $(OBJ)
	@make chrono -C $(LIB_PATH)
	@make clean -C $(LIB_PATH)
	@gcc -ltermcap $^ -o $@ -L $(LIB_PATH) -lft
	@printf "${GREEN}ft_select project compilation finished, executable ft_select ready${NC}"
	@echo

$(LIB):
	@make chrono -C $(LIB_PATH)
	@make clean -C $(LIB_PATH)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) && gcc $(FLAGS) $(INC) -o $@ -c $<

clean : 
	@rm -rf $(OBJ_PATH)
	@printf "${RED}ft_select's object files deleted.${NC}\n"

fclean : clean
	@rm -f $(NAME)
	@printf "${RED}Executable ft_select deleted.${NC}\n"

re : fclean all
