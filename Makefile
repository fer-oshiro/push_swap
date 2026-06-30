NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = main.c

# Makeflags
MAKEFLAGS += --no-print-directory

# Colors
RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Programa criado ${RED} ⸜(｡˃ ᵕ ˂ )⸝♡ "


%.o: %.c
	@echo "⋆.˚${BLUE} Compiling:${RESET} $< to $@ ⋆.˚"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo " ${YELLOW} ( -_•) ▄︻デ══━一 ${RESET}project objects"
	@rm -f $(OBJS)

fclean: clean
	@echo " ${YELLOW} ( -_•) ▄︻デ══━一 ${RESET}everything"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test cleantest