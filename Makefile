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
					init.c \
					operations.c \
					operations2.c \
					free.c \
					utils.c \
					print.c \
					linkedlistfunctions.c \
					errors.c \
					check.c \
					sort.c \
					sort2.c \
					chunk.c \
					index.c

SRC = $(addprefix $(SRC_DIR)/,$(SOURCES))

# OBJS

OBJS_DIR 		= objs
OBJS 			= $(addprefix ./$(OBJS_DIR)/,$(SOURCES:.c=.o))
OBJS_DIRFS 		= objsfs
OBJSFS 			= $(addprefix ./$(OBJS_DIRFS)/,$(SOURCES:.c=.o))

# Compiling

CC				= gcc

CFLAGS 			= -Wall -Werror -Wextra

INCLUDE 		= -I include

all: temp $(NAME)

temp:
	@mkdir -p $(OBJS_DIR)

tempfs:
	@mkdir -p $(OBJS_DIRFS)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(LIB_INC) $(INCLUDE) -c $< -o $@
	@echo "Compiling $@..."

$(NAME):	$(OBJS)
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN) Libft compiled $(END)"
	@make -s -C $(FT_PRINTF_DIR)
	@echo "$(GREEN) Ft_printf compiled $(END)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_LNK) $(FT_PRINTF_LNK) -o $(NAME)
	@echo "$(GREEN) $(NAME) Compiled $(END)"

$(OBJS_DIRFS)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIRFS)
	@$(CC) -g3 -fsanitize=address $(CFLAGS) $(LIB_INC) $(INCLUDE) -c $< -o $@
	@echo "Compiling $@..."

fsanitize: tempfs	$(OBJSFS)
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN) Libft compiled $(END)"
	@make -s -C $(FT_PRINTF_DIR)
	@echo "$(BLUE) Ft_printf compiled $(END)"
	@$(CC) $(CFLAGS) -g3 -fsanitize=address -static-libasan $(OBJSFS) $(LIB_LNK) $(FT_PRINTF_LNK) -o debug
	@echo "$(BLUE) $(NAME) Compiled $(END)"

checkfunction:
	$(shell nm -A ./objs/*) > checkfunction.txt

git:
	git add .
	git commit -am "update"
	git push

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_DIRFS)
	@rm -rf norminette.txt
	@rm -rf checkfunction.txt
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(FT_PRINTF_DIR) clean
	@echo "$(BLUE)$(NAME) Cleaning Done$(END)"

fclean: clean
	@rm -rf $(NAME)
	@rm -f debug
	@make -sC $(LIBFT_DIR) fclean
	@make -sC $(FT_PRINTF_DIR) fclean
	@echo "$(BLUE)$(NAME) Fcleaning Done$(END)"

re: fclean all

.PHONY: all fclean clean re temp