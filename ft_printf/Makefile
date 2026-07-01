NAME = libftprintf.a
CC = cc
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes -I$(LIBFT_DIR)

SRCS = src/ft_printf.c \
    src/utils/ft_printf_char.c \
    src/utils/ft_printf_string.c \
    src/utils/ft_printf_pointer.c \
    src/utils/ft_printf_digit.c \
    src/utils/ft_printf_unsigned_digit.c \
    src/utils/ft_printf_hex.c

OBJS = $(SRCS:.c=.o)

# Makeflags
MAKEFLAGS += --no-print-directory


TEST_DIR = tests
TEST_NAME = $(TEST_DIR)/test
TEST_SRC = $(TEST_DIR)/main.c

# Colors
RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "⋆.˚  ${BLUE}Building library:${RESET} ${NAME} ˚.⋆"
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
    
test: $(NAME)
	@mkdir -p $(TEST_DIR)
	@if [ ! -f $(TEST_SRC) ]; then \
		echo '#include "ft_printf.h"\nint main(void)\n{\n    ft_printf("test :D\\n");\n    return (0);\n}' > $(TEST_SRC); \
	fi
	@echo " 🚀 ${GREEN}Compiling test program inside $(TEST_DIR)/...${RESET}"
	@$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) -o $(TEST_NAME)
	@echo " 🎉 ${GREEN}Done! Run with: ./${TEST_NAME}${RESET}"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(TEST_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean

cleantest:
	@echo " 🗑️ ${RED}Removing test directory...${RESET}"
	@rm -rf $(TEST_DIR)

re: fclean all

.PHONY: all clean fclean re test cleantest