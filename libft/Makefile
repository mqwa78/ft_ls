SRCS = ./strings/ft_strlcpy.c \
	   ./strings/ft_strcpy.c \
	   ./strings/ft_strlcat.c \
	   ./strings/ft_strcat.c \
	   ./strings/ft_atoi.c \
	   ./strings/ft_split.c \
       ./strings/ft_strnstr.c \
	   ./strings/ft_itoa.c \
	   ./strings/ft_strmapi.c \
	   ./strings/ft_striteri.c \
	   ./strings/ft_strjoin.c \
       ./strings/ft_substr.c \
	   ./strings/ft_strdup.c \
	   ./strings/ft_strndup.c \
	   ./strings/ft_strrchr.c \
	   ./strings/ft_strchr.c \
	   ./strings/ft_strncmp.c \
	   ./strings/ft_strcmp.c \
	   ./strings/ft_strlen.c \
	   ./strings/ft_strtrim.c \
	   ./print/ft_putnbr_fd.c \
       ./print/ft_putendl_fd.c \
	   ./print/ft_putstr_fd.c \
	   ./print/ft_putchar_fd.c \
	   ./print/ft_putnchar_fd.c \
	   ./printf/ft_printf.c \
	   ./printf/ft_putchar.c \
	   ./printf/ft_putnbr.c \
	   ./printf/ft_putstr.c \
	   ./printf/ft_putaddr.c \
	   ./printf/ft_put_unsigned_n.c \
	   ./printf/ft_putupper_hexa.c \
	   ./printf/ft_putlower_hexa.c \
	   ./printf/ft_putlld.c \
	   ./memory/ft_calloc.c \
	   ./memory/ft_memcpy.c \
	   ./memory/ft_memcmp.c \
	   ./memory/ft_memchr.c \
	   ./memory/ft_memmove.c \
	   ./memory/ft_bzero.c \
	   ./memory/ft_memset.c \
	   ./ctypes/ft_isalpha.c \
	   ./ctypes/ft_isspace.c \
	   ./ctypes/ft_isalnum.c \
	   ./ctypes/ft_isascii.c \
	   ./ctypes/ft_isdigit.c \
       ./ctypes/ft_isprint.c \
	   ./ctypes/ft_tolower.c \
	   ./ctypes/ft_toupper.c \
	   ./list/ft_lstnew.c \
       ./list/ft_lstadd_front.c \
	   ./list/ft_lstsize.c \
       ./list/ft_lstlast.c \
	   ./list/ft_lstdelone.c \
	   ./list/ft_lstclear.c \
       ./list/ft_lstiter.c \
	   ./list/ft_lstmap.c \
	   ./list/ft_lstadd_back.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
