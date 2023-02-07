CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

LIBFT= 	libft/libft.a

SRCS 	=	push_swap.c utils.c\
			ft_parse.c utils_2.c\
			save_to_list.c new_list.c \
			ft_swap.c ft_push.c \
			sort_little.c sort_big.c \
			ft_rotate.c ft_rotate_reverse.c \
			find_max_min.c get_cmds.c ft_min_commands.c

SRCS_BONUS = checker.c ft_parse.c \
			save_to_list.c  utils.c\
			new_list.c ft_swap.c  utils_2.c\
			ft_push.c ft_rotate.c ft_rotate_reverse.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c

DEPS	=	push_swap.h \
			libft/libft.h \
			gnl/get_next_line.h

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${SRCS_BONUS:.c=.o}

all:		$(NAME)

bonus:		$(BONUS_NAME)

.c.o: ${SRCS}
			@$(CC) $(CFLAGS) -o $@ -c $<
			@printf '\033[0;36mObject $@ [\033[0;32m✔\033[0;36m]\n\033[0m'

$(LIBFT):
			@make -C "libft"

$(NAME):	$(OBJS) $(LIBFT) $(DEPS) libft/*.c
			@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
			@printf '\033[1;32mPush-Swap compile success!\n\033[0m'

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(DEPS) libft/*.c
			@$(CC) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
			@printf '\033[1;32mChecker compile success!\n\033[0m'

clean:		
			@$(RM) $(OBJS) $(BONUS_OBJS)
			@make clean -C "libft"
			@printf '\033[1;35m%s\n\033[0m' "Clean Objects"

fclean:		clean
			@$(RM) $(NAME) $(BONUS_NAME)
			@make fclean -C "libft"
			@printf '\033[1;35m%s\n\033[0m' "Clean Push-Swap"

re:			fclean all

.PHONY:		all clean fclean re
