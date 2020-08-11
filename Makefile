# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cspaghet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/01 17:25:05 by cspaghet          #+#    #+#              #
#    Updated: 2020/08/01 17:25:11 by cspaghet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker

SRC_DIR = ./srcs/
SRC =   checker.c \
        commands.c \
        commands2.c \
        oper_lists.c \
        oper_lists2.c \


SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC = push_swap.h
INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))

LIB_OBJ = *.o
LIB_OBJ_DIR = ./libft/obj/
LIB_OBJS = $(addprefix $(LIB_OBJ_DIR), $(LIB_OBJ))

PF_OBJ = *.o
PF_OBJ_DIR = ./libft/obj/ft_printf/
PF_OBJS = $(addprefix $(PF_OBJ_DIR), $(PF_OBJ))
SRC_PF_DIR = ./libft/srcs/ft_printf/

LIB_INC = libft.h get_next_line.h ft_printf.h
LIB_INCS = $(addprefix $(INC_DIR), $(LIB_INC))

LIB_SRC_DIR = ./libft/srcs/

FLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

all: $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJ_DIR) $(LIB_OBJS) $(PF_OBJ_DIR) $(OBJS)
		clang $(OBJS) ./libft/libft.a -o $(NAME_CHECKER)

$(OBJ_DIR):
		mkdir -p $@
		mkdir -p $(LIB_OBJ_DIR)
		mkdir -p ./libft/obj/ft_printf/

$(LIB_OBJ_DIR)%.o: $(LIB_SRC_DIR)%.c $(LIB_INCS)
		make -C ./libft/

$(PF_OBJ_DIR)%.o: $(SRC_PF_DIR)%.c $(LIB_INCS)
		make -C ./libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		clang $(FLAGS) -o $@ -c $<

clean:
		@make clean -C libft
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
