NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory

SRCS        = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRINTF_DIR  = ./ft_printf
SRCS_PRINTF = $(PRINTF_DIR)/src/ft_printf.c \
			$(PRINTF_DIR)/src/utils/ft_printf_char.c \
			$(PRINTF_DIR)/src/utils/ft_printf_string.c \
			$(PRINTF_DIR)/src/utils/ft_printf_pointer.c \
			$(PRINTF_DIR)/src/utils/ft_printf_digit.c \
			$(PRINTF_DIR)/src/utils/ft_printf_unsigned_digit.c \
			$(PRINTF_DIR)/src/utils/ft_printf_hex.c

GNL_DIR     = ./get_next_line
SRCS_GNL    = $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c 

INCLUDES    = -I. -I includes -I $(PRINTF_DIR)/includes -I $(GNL_DIR)
ALL_SRCS    = $(SRCS) $(SRCS_PRINTF) $(SRCS_GNL)

OBJS        = $(ALL_SRCS:.c=.o)

AR          = ar rcs
RM          = rm -f

# Colors
RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[1;34m
CYAN   := \033[36m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "⋆.˚ ${BLUE} Creating:${RESET} libft  ˚.⋆"
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re