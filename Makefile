NAME 			= push_swap

# Colors
GREEN			=	\033[0;32m
RED				=	\033[0;31m
BLUE			=	\033[0;34m
END				=	\033[0m

# Ft_printf
FT_PRINTF_DIR	= ft_printf
FT_PRINTFA		= $(addprefix ./$(FT_PRINTF_DIR)/, libftprintf.a)
FT_PRINTF_INC	= -I $(LIBFT_DIR)
FT_PRINTF_LNK	= -L $(FT_PRINTF_DIR) -lftprintf

# Libft

LIBFT_DIR		= libft
LIBFTA			= $(addprefix ./$(LIBFT_DIR)/, libft.a)
LIB_INC			= -I $(LIBFT_DIR)
LIB_LNK			= -L $(LIBFT_DIR) -lft


# SRCS

SRC_DIR			= src

SOURCES			= main.c \
					operations.c \
					utils.c \
					utils2.c \
					print.c \


SRC = $(addprefix $(SRC_DIR)/,$(SOURCES))

# OBJS

OBJS_DIR 		= objs

OBJS 			= $(addprefix ./$(OBJS_DIR)/,$(SOURCES:.c=.o))

# Compiling

CC				= gcc

CFLAGS 			= -Wall -Werror -Wextra

INCLUDE 		= -I include

all: temp $(NAME)

temp:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(LIB_INC) $(INCLUDE) -c $< -o $@
	@echo "Compiling..."

$(NAME):	$(OBJS)
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN) Libft compiled $(END)"
	@make -s -C $(FT_PRINTF_DIR)
	@echo "$(BLUE) Ft_printf compiled $(END)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_LNK) $(FT_PRINTF_LNK) -o $(NAME)
	@echo "$(BLUE) $(NAME) Compiled $(END)"


checkfunction:
	$(shell nm -A ./objs/*) > checkfunction.txt

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf norminette.txt
	@rm -rf checkfunction.txt
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(FT_PRINTF_DIR) clean
	@echo "$(NAME) Cleaning Done"

fclean: clean
	@rm -rf $(NAME)
	@make -sC $(LIBFT_DIR) fclean
	@make -sC $(FT_PRINTF_DIR) fclean
	@echo "$(NAME) Fcleaning Done"

re: fclean all

.PHONY: all fclean clean re temp