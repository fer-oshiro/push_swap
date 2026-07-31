NAME = push_swap
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g3
OBJS = $(SRCS:.c=.o)
SRCS = main.c parse_flag.c parse_int.c \
		handle_data.c handle_number_token.c \
		parse_flag_strategy.c parse_sort.c \
		utils_split.c utils_list.c stack_utils.c \
		disorder_metric.c benchmark.c stack_indexes.c \
		sort_small.c \
		handle_op_push.c handle_op_rotate.c \
		handle_op_reverse_rotate.c handle_op_swap.c \
		sort_complex.c sort_medium.c sort_simples.c


# Makeflags
MAKEFLAGS += --no-print-directory

# libft com a printf
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -I includes -I $(LIBFT_DIR)

# Colors
RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[1;34m
CYAN   := \033[36m
RESET := \033[0m
BOLD  := \033[1m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@printf '\n'
	@printf '%b\n' "$(BLUE)˖°..˖.˖ִ˖⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆˖..˖ִ˖°.˖.˖°.˖°˖°.˖.˖ִ˖°.˖°☁︎｡⋆｡ ﾟ☾ ˖°.˖..˖.˖ִ˖°..˖.˖.$(RESET)"
	@printf '%b\n' "$(CYAN)˖°..˖.˖ִ˖°.˖°.˖       .°.˖ִ˖°˖.˖°.˖°˖°.˖.˖ִ˖°.˖°˖°.˖..˖.˖ִ      ｡⋆｡☾ ﾟ｡⋆˖.˖.$(RESET)"
	@printf '%b\n' "$(CYAN)˖°.⋆｡ﾟ☁︎⋆｡ ﾟ｡⋆.˖  ִ$(RESET)🛸$(CYAN)  .˖°.˖  $(RESET)$(BOLD)Build Successful$(CYAN)  .˖°⋆｡.˖  ִ$(YELLOW)🛸$(CYAN)  .˖°⋆｡ﾟ｡⋆｡⋆˖.˖ִ$(RESET)"
	@printf '%b\n' "$(CYAN)˖°ִ˖..˖.˖ִ˖☁︎｡⋆°.˖      ˖ִ˖°.˖.˖°.˖°˖°⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆˖°.˖°˖     ..˖.˖ִ˖°..˖.˖.$(RESET)"
	@printf '%b\n' "$(BLUE)˖°..˖.˖ִ˖°.˖°.˖⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆.˖°˖°˖°.˖.˖ִ˖°.˖°˖°.˖⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆.˖ִ˖°..˖.˖.$(RESET)"
	@printf '\n'
	@printf '%b\n' "${RED} ﮩ٨ـﮩ❤︎ﮩ٨ـ♡ﮩﮩ٨ـﮩ❤︎ﮩ٨ـﮩ (っ˶ ˘ ᵕ˘)ˆᵕ ˆ˶ς) 𝕋𝕙𝕒𝕟𝕜 𝕪𝕠𝕦✮˚.⋆ ﮩ٨ـﮩ❤︎ﮩ٨ـ♡ﮩﮩ٨ـﮩ❤︎ﮩ٨ـﮩ"
	@printf '\n'

%.o: %.c
	@printf '%b\n' "⋆.˚ ${BLUE} Compiling:${RESET} $< to $@ ˚.⋆"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): FORCE
	@make -C $(LIBFT_DIR)

FORCE:

clean:
	@printf '\n'
	@printf '%b\n' " ${BLUE} ( -_•) ▄︻デ══━一 . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.  ${RESET}Cleaning: project objects ${BLUE}  . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.${RESET}"
	@rm -f $(OBJS)
	@printf '%b\n' " ${BLUE} ( -_•) ▄︻デ══━一 . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.  ${RESET}Cleaning: libft           ${BLUE}  . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.${RESET}"
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@printf '%b\n' " ${BLUE} ( -_•) ▄︻デ══━一 . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.  ${RESET}Cleaning: everything ${BLUE}       . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.${RESET}"
	@printf '\n'
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re FORCE
