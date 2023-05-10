# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 11:28:22 by wkrippne          #+#    #+#              #
#    Updated: 2023/04/18 22:20:39 by wkrippne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		= push_swap
BONUS		= checker
LIBFT		= lib/libft
PRINTF		= lib/ft_printf
GNL			= lib/GNL/
SRC_DIR		= src/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -f

FILES		=	push_swap sorting sort_a_b sortfast utils msg op_pa_pb op_rx op_rrx op_sx
BS_FILES	=   checker bs_utils sorting sort_a_b sortfast utils msg op_pa_pb op_rx op_rrx op_sx
GNL_FILES	=   get_next_line get_next_line_utils
SRC_FILES	=   $(addprefix $(SRC_DIR), $(FILES))
SRC_BSFILES	=   $(addprefix $(SRC_DIR), $(BS_FILES))
SRC_GFILES	=   $(addprefix $(GNL), $(GNL_FILES))
SRC			=   $(addsuffix .c, $(SRC_FILES))
BSSRC		=   $(addsuffix .c, $(SRC_BSFILES))
GNLSRC		=   $(addsuffix .c, $(SRC_GFILES))
OBJ			=   $(addsuffix .o, $(SRC_FILES))
BSOBJ		=   $(addsuffix .o, $(SRC_BSFILES))
GNLOBJ		=   $(addsuffix .o, $(SRC_GFILES))

all:	$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp lib/libft/libft.a .
			@make -C lib/ft_printf
			@cp lib/ft_printf/libftprintf.a .
			@$(CC) $(CFLAGS) $(OBJ) libft.a libftprintf.a -o $(NAME)

clean:
			@$(RM) $(OBJ)
			@$(RM) $(BSOBJ)
			@$(RM) $(GNLOBJ)
			@make clean -C $(LIBFT)
			@make clean -C $(PRINTF)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(BONUS)
			@$(RM) libft.a
			@$(RM) $(LIBFT)/libft.a
			@$(RM) libftprintf.a
			@$(RM) $(PRINTF)/libftprintf.a
			@rm -rf *.dSYM

re:			fclean all

bonus:		$(BONUS)

$(BONUS):	$(BSOBJ) $(GNLOBJ)
			@make -C $(LIBFT)
			@cp lib/libft/libft.a .
			@make -C lib/ft_printf
			@cp lib/ft_printf/libftprintf.a .
			@$(CC) $(CFLAGS) $(BSSRC) $(GNLSRC) libft.a libftprintf.a -o $(BONUS)

norm:
			@clear
			@norminette $(SRC) $(BSSRC) $(GNLSRC) $(LIBFT) $(PRINTF) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re bonus norm
