NAME_CHECKER = checker
NAME_PUSH_SWAP = push_swap

SRC_DIR = ./srcs/
SRC =   			ft_data.c ft_push.c ft_reverse_rotate.c \
					ft_rotate.c ft_stack.c ft_swap.c ft_valid.c \
					ft_error.c ft_isnum.c ft_newatoi.c
SRC_PUSH_SWAP =		push_swap.c ft_info.c sort_insert.c sort_insert2.c \
					sort_insert3.c sort_six.c chunk.c chunk2.c ft_sort_six.c
SRC_CHECKER =		checker.c go_ft.c


SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRCS_PUSH_SWAP = $(addprefix $(SRC_DIR), $(SRC_PUSH_SWAP))
SRCS_CHECKER = $(addprefix $(SRC_DIR), $(SRC_CHECKER))


OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJS_PUSH_SWAP = $(addprefix $(OBJ_DIR), $(OBJ_PUSH_SWAP))
OBJS_CHECKER = $(addprefix $(OBJ_DIR), $(OBJ_CHECKER))


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

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME_PUSH_SWAP) $(NAME_CHECKER)

$(NAME_PUSH_SWAP): $(OBJ_DIR) $(LIB_OBJS) $(PF_OBJ_DIR) $(OBJS) $(OBJS_PUSH_SWAP)
		@clang $(OBJS) $(OBJS_PUSH_SWAP) ./libft/libft.a -o $(NAME_PUSH_SWAP)
		@echo "\n$(NAME_PUSH_SWAP): $(GREEN)$(NAME_PUSH_SWAP) object files were created$(RESET)"
		@echo "$(NAME_PUSH_SWAP): $(GREEN)$(NAME_PUSH_SWAP) was created$(RESET)"

$(NAME_CHECKER): $(OBJ_DIR) $(LIB_OBJS) $(PF_OBJ_DIR) $(OBJS) $(OBJS_CHECKER)
		@clang $(OBJS) $(OBJS_CHECKER) ./libft/libft.a -o $(NAME_CHECKER)
		@echo "\n$(NAME_PUSH_SWAP): $(GREEN)$(NAME_CHECKER) object files were created$(RESET)"
		@echo "$(NAME_PUSH_SWAP): $(GREEN)$(NAME_CHECKER) was created$(RESET)"

$(OBJ_DIR):
		@mkdir -p $(LIB_OBJ_DIR)
		@echo "libft: $(GREEN)$(LIB_OBJ_DIR) was created$(RESET)"
		@mkdir -p ./libft/obj/ft_printf/
		@echo "libft: $(GREEN)./libft/obj/ft_printf/ was created$(RESET)"
		@mkdir -p $@
		@echo "$(NAME_PUSH_SWAP): $(GREEN)$(LIB_OBJ_DIR) was created$(RESET)"

$(LIB_OBJ_DIR)%.o: $(LIB_SRC_DIR)%.c $(LIB_INCS)
		@echo "$(NAME_PUSH_SWAP): $(GREEN)creating libft...$(RESET)"
		@make -C ./libft/

$(PF_OBJ_DIR)%.o: $(SRC_PF_DIR)%.c $(LIB_INCS)
		@echo "$(NAME_PUSH_SWAP): $(GREEN)creating libft/ft_printf...$(RESET)"
		@make -C ./libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		@clang $(FLAGS) -o $@ -c $<
		@echo "$(GREEN).$(RESET)\c"

clean:
		@make clean -C libft
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)
		@echo "$(NAME_PUSH_SWAP): $(RED)$(OBJ_DIR) was deleted$(RESET)"
		@echo "$(NAME_PUSH_SWAP): $(RED)object files were deleted$(RESET)"

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME_PUSH_SWAP)
		@echo "$(NAME_PUSH_SWAP): $(RED)$(NAME_PUSH_SWAP) was deleted$(RESET)"
		@rm -f $(NAME_CHECKER)
        @echo "$(NAME_PUSH_SWAP): $(RED)$(NAME_CHECKER) was deleted$(RESET)"


re: fclean all

.PHONY: all clean fclean re norme