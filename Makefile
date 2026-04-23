SRCS = ./srcs/main.c \
       ./srcs/ft_ls.c \
	   ./srcs/utils.c \
	   ./srcs/sort.c \
	   ./srcs/print_error.c \

OBJS = $(SRCS:.c=.o)

NAME = ft_ls
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I libft/includes/
LIBFT = libft/
LIB = -L $(LIBFT) -lft

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
RESET = \033[0m

all: lib $(NAME)

lib:
	@echo "$(BLUE)📚 Compilation de la libft...$(RESET)"
	@$(MAKE) -s -C $(LIBFT) --no-print-directory
	@echo "$(GREEN)✔ libft prête !$(RESET)"

$(NAME): $(OBJS)
	@echo "$(YELLOW)🔧 Compilation de $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIB) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) prêt !$(RESET)"

%.o: %.c
	@echo "$(BLUE)⚙️  Compilation $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)🧹 Nettoyage des objets...$(RESET)"
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT) clean --no-print-directory

fclean: clean
	@echo "$(RED)🗑 Suppression de $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re lib