# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acottier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 13:55:41 by acottier          #+#    #+#              #
#    Updated: 2016/09/21 11:25:41 by acottier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
NC		=\033[0m

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC_NAMES = ft_strclr.c \
			ft_strrmv.c \
			ft_atoi.c \
			ft_strcmp.c \
			ft_bzero.c \
			ft_strcpy.c \
			ft_isalnum.c \
			ft_strdel.c \
			ft_isalpha.c \
			ft_strdup.c \
			ft_isascii.c \
			ft_strequ.c \
			ft_isdigit.c \
			ft_striter.c \
			ft_isprint.c \
			ft_striteri.c \
			ft_itoa.c \
			ft_strjoin.c \
			ft_memalloc.c \
			ft_strlcat.c \
			ft_memccpy.c \
			ft_strlen.c \
			ft_memchr.c \
			ft_strmap.c \
			ft_memcmp.c \
			ft_strmapi.c \
			ft_memcpy.c \
			ft_strncat.c \
			ft_memdel.c \
			ft_strncmp.c \
			ft_memmove.c \
			ft_strncpy.c \
			ft_memset.c \
			ft_strnequ.c \
			ft_putchar.c \
			ft_strnew.c \
			ft_putchar_fd.c \
			ft_strnstr.c \
			ft_putendl.c \
			ft_strrchr.c \
			ft_putendl_fd.c \
			ft_strsplit.c \
			ft_putnbr.c \
			ft_strstr.c \
			ft_putnbr_fd.c \
			ft_strsub.c \
			ft_putstr.c \
			ft_strtrim.c \
			ft_putstr_fd.c \
			ft_tolower.c \
			ft_strcat.c \
			ft_toupper.c \
			ft_strchr.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_sqrt.c \
			ft_power.c \
			ft_reverse.c \
			ft_strdupchr.c \
			ft_strlenchr.c \
			ft_factorial.c \
			ft_puttab.c \
			ft_freetab.c \
			ft_newtab.c \
			ft_putstr_err.c \
			ft_trijoin.c \
			ft_doublestr.c \
			ft_addspace.c \
			ft_nbrlength.c \
			ft_triplestr.c \
			ft_stradv.c \
			ft_smallest.c \
			ft_tabsize.c \
			ft_clearnstr.c \
			ft_tabdup.c \
			ft_strndup.c \
			ft_putendl_err.c \
			ft_capitalize.c \
			ft_putchar_err.c

OBJ_NAMES = $(SRC_NAMES:.c=.o)
INC_NAMES = libft.h

all : $(NAME)

$(NAME) : 
	@gcc -c $(FLAGS) $(SRC_NAMES)
	@ar rc $(NAME) $(OBJ_NAMES)
	@ranlib $(NAME)
	@printf "${GREEN}Library compilation finished.${NC}\n"

clean :
	@rm -f $(OBJ_NAMES)
	@printf "${RED}Library object files deleted.${NC}\n"

fclean : clean
	@rm -f $(NAME)
	@printf "${RED}Library deleted.${NC}\n"

re : fclean all

norme :
	@norminette $(SRC_NAMES)
	@norminette $(INC_NAMES)

chrono : fclean
	@(time gcc -c $(FLAGS) $(SRC_NAMES) && ar rc $(NAME) $(OBJ_NAMES) && ranlib $(NAME)) 2> time.txt
	@printf "${GREEN}Library compilation finished : ${NC}"
	@printf "${YELLOW}"
	@cat time.txt | head -2 | tail -1
	@printf "${NC}"
	@rm time.txt
