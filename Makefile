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
CYAN   := \033[36m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n"
	@echo "$(BLUE)˖°..˖.˖ִ˖⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆˖..˖ִ˖°.˖.˖°.˖°˖°.˖.˖ִ˖°.˖°☁︎｡⋆｡ ﾟ☾ ˖°.˖..˖.˖ִ˖°..˖.˖.$(RESET)"
	@echo "$(CYAN)˖°..˖.˖ִ˖°.˖°.˖       .°.˖ִ˖°˖.˖°.˖°˖°.˖.˖ִ˖°.˖°˖°.˖..˖.˖ִ      ｡⋆｡☾ ﾟ｡⋆˖.˖.$(RESET)"
	@echo "$(CYAN)˖°.⋆｡ﾟ☁︎⋆｡ ﾟ｡⋆.˖  ִ$(RESET)🛸$(CYAN)  .˖°.˖  $(RESET)Build Successful$(CYAN)  .˖°⋆｡.˖  ִ$(YELLOW)🛸$(CYAN)  .˖°⋆｡ﾟ｡⋆｡⋆˖.˖ִ$(RESET)"
	@echo "$(CYAN)˖°ִ˖..˖.˖ִ˖☁︎｡⋆°.˖      ˖ִ˖°.˖.˖°.˖°˖°⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆˖°.˖°˖     ..˖.˖ִ˖°..˖.˖.$(RESET)"
	@echo "$(BLUE)˖°..˖.˖ִ˖°.˖°.˖⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆.˖°˖°˖°.˖.˖ִ˖°.˖°˖°.˖⋆｡ﾟ☁︎｡⋆｡ ﾟ☾ ﾟ｡⋆.˖ִ˖°..˖.˖.$(RESET)"
	@echo "\n"
	@echo "${RED} ﮩ٨ـﮩ❤︎ﮩ٨ـ♡ﮩﮩ٨ـﮩ❤︎ﮩ٨ـﮩ (っ˶ ˘ ᵕ˘)ˆᵕ ˆ˶ς) 𝕋𝕙𝕒𝕟𝕜 𝕪𝕠𝕦✮˚.⋆ ﮩ٨ـﮩ❤︎ﮩ٨ـ♡ﮩﮩ٨ـﮩ❤︎ﮩ٨ـﮩ"
	@echo "\n"

%.o: %.c
	@echo "⋆.˚ ${BLUE} Compiling:${RESET} $< to $@ ˚.⋆"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\n"
	@echo " ${BLUE} ( -_•) ▄︻デ══━一 . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.  ${RESET}Cleaning: project objects ${BLUE}  . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.${RESET}"
	@rm -f $(OBJS)

fclean: clean
	@echo " ${BLUE} ( -_•) ▄︻デ══━一 . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.  ${RESET}Cleaning: everything ${BLUE}       . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁.${RESET}"
	@echo "\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re