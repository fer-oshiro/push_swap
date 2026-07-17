NAME = push_swap
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g3
OBJS = $(SRCS:.c=.o)
SRCS = main.c parse_flag.c parse_int.c \
		handle_data.c handle_number_token.c \
		parse_flag_strategy.c parse_sort.c \
		utils_split.c utils_list.c \
		disorder_metric.c \
		handle_op_push.c handle_op_rotate.c handle_op_swap.c


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
	@echo -e  "\n"
	@echo -e "$(BLUE)˖°..˖.˖ִ˖⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆˖..˖ִ˖°.˖.˖°.˖°˖°.˖.˖ִ˖°.˖°☁︎｡⋆｡ ﾟ☾ ˖°.˖..˖.˖ִ˖°..˖.˖.$(RESET)"
	@echo -e "$(CYAN)˖°..˖.˖ִ˖°.˖°.˖       .°.˖ִ˖°˖.˖°.˖°˖°.˖.˖ִ˖°.˖°˖°.˖..˖.˖ִ      ｡⋆｡☾ ﾟ｡⋆˖.˖.$(RESET)"
	@echo -e "$(CYAN)˖°.⋆｡ﾟ☁︎⋆｡ ﾟ｡⋆.˖  ִ$(RESET)🛸$(CYAN)  .˖°.˖  $(RESET)$(BOLD)Build Successful$(CYAN)  .˖°⋆｡.˖  ִ$(YELLOW)🛸$(CYAN)  .˖°⋆｡ﾟ｡⋆｡⋆˖.˖ִ$(RESET)"
	@echo -e "$(CYAN)˖°ִ˖..˖.˖ִ˖☁︎｡⋆°.˖      ˖ִ˖°.˖.˖°.˖°˖°⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆˖°.˖°˖     ..˖.˖ִ˖°..˖.˖.$(RESET)"
	@echo -e "$(BLUE)˖°..˖.˖ִ˖°.˖°.˖⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆.˖°˖°˖°.˖.˖ִ˖°.˖°˖°.˖⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆.˖ִ˖°..˖.˖.$(RESET)"
	@echo -e "\n"
	@echo -e "${RED} ﮩ٨ـﮩ❤︎ﮩ٨ـ♡ﮩﮩ٨ـﮩ❤︎ﮩ٨ـﮩ (っ˶ ˘ ᵕ˘)ˆᵕ ˆ˶ς) 𝕋𝕙𝕒𝕟𝕜 𝕪𝕠𝕦✮˚.⋆ ﮩ٨ـﮩ❤︎ﮩ٨ـ♡ﮩﮩ٨ـﮩ❤︎ﮩ٨ـﮩ"
	@echo -e "\n"

%.o: %.c
	@echo -e "⋆.˚ ${BLUE} Compiling:${RESET} $< to $@ ˚.⋆"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): FORCE
	@make -C $(LIBFT_DIR)

FORCE: 

clean:
	@echo -e "\n"
	@echo -e " ${BLUE} ( -_•) ▄︻デ══━一 . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.  ${RESET}Cleaning: project objects ${BLUE}  . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.${RESET}"
	@rm -f $(OBJS)
	@echo -e " ${BLUE} ( -_•) ▄︻デ══━一 . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.  ${RESET}Cleaning: libft           ${BLUE}  . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.${RESET}"
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo -e " ${BLUE} ( -_•) ▄︻デ══━一 . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.  ${RESET}Cleaning: everything ${BLUE}       . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.${RESET}"
	@echo -e "\n"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re FORCE
