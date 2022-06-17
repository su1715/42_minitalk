# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 14:13:33 by sujpark           #+#    #+#              #
#    Updated: 2021/12/06 17:58:33 by sujpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_atoi ft_bzero ft_calloc \
		ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
		ft_memcmp ft_memcpy ft_memmove ft_memset ft_memchr\
		ft_strchr ft_strdup ft_strlcat ft_strlcpy \
		ft_strlen ft_strncmp ft_strnstr ft_strrchr \
		ft_tolower ft_toupper \
		ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi \
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_striteri

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
