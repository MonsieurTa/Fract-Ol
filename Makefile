# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wta <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 02:51:44 by wta               #+#    #+#              #
#    Updated: 2018/12/09 07:42:47 by wta              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ====================================================================== COLOR #
_GREEN		=	\033[0;32m
_WHITE		=	\033[m
_YELLOW		=	\033[0;33m
_DYELLOW	=	\x1b[33;01m
# VARIABLES ===================================================================#
NAME		=	fractol
OBJ			=	$(SRCS:.c=.o)
LIBFT		=	-L libft -lft
MLXLIB		=	-L /usr/local/lib -lmlx
MLXFLAG		=	-framework OpenGL -framework Appkit
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Ofast
SRCS		=	main.c				\
				fractal.c			\
				fractal_bailout.c	\
				event.c	event2.c	\
				event3.c			\
				set_fractal.c		\
				utils.c
# RULES =======================================================================#
all		:	$(NAME)
# NAME ========================================================================#
$(NAME)	:	$(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLXLIB) $(MLXFLAG)
	@echo "$(_GREEN)[COMPILED]$(_WHITE)" $@
# OBJECTS =====================================================================#
%.o	:	%.c ./fractol.h
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(_GREEN)[OK]$(_WHITE) $@"
# CLEAN =======================================================================#
clean	:	| ftclean
	@rm -f $(OBJ)
	@echo "$(_YELLOW)[DELETED]$(_WHITE)" $(OBJ)
# FCLEAN ======================================================================#
fclean	:	clean | ftfclean
	@rm -f $(NAME)
	@echo "$(_YELLOW)[DELETED]$(_WHITE)" $(NAME)
# FTCLEAN =====================================================================#
ftclean	:
	@$(MAKE) -C libft clean
# FTFCLEAN ====================================================================#
ftfclean:
	@$(MAKE) -C libft fclean
# RE ==========================================================================#
re		: fclean all
# END MAKEFILE ================================================================#
