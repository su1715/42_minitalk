# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujpark <sujpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 21:28:58 by sujpark           #+#    #+#              #
#    Updated: 2022/06/16 22:01:30 by sujpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME = minitalk
SERVER = server
CLIENT = client

OBJ_DIR = ./obj

# SERVER_BONUS_SRCS = server_bonus.c \
# 			minitalk_utils_bonus.c
# CLIENT_BONUS_SRCS = client_bonus.c \
# 			minitalk_utils_bonus.c
SERVER_SRCS = server.c \
			minitalk_utils.c
CLIENT_SRCS = client.c \
			minitalk_utils.c

# ifdef IS_BONUS
# 	SERVER_INCS = minitalk_bonus.h
# 	SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_BONUS_SRCS:.c=.o))
# 	CLIENT_INCS = minitalk_bonus.h
# 	CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_BONUS_SRCS:.c=.o))
# else
	SERVER_INCS = minitalk.h
	SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_SRCS:.c=.o))
	CLIENT_INCS = minitalk.h
	CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_SRCS:.c=.o))
# endif

LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

LIBFTPRINTF_DIR = ./ft_printf
LIBFTPRINTF_NAME = ftprintf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/lib$(LIBFTPRINTF_NAME).a

all : $(NAME)

bonus :
	make IS_BONUS=1 all

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : $(LIBFT) $(LIBFTPRINTF) $(SERVER_OBJS) $(SERVER_INCS)
	$(CC) $(CFLAGS) -I ./ $(SERVER_OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -L $(LIBFTPRINTF_DIR) -l $(LIBFTPRINTF_NAME) -o $@

$(CLIENT) : $(LIBFT) $(LIBFTPRINTF) $(CLIENT_OBJS) $(CLIENT_INCS)
	$(CC) $(CFLAGS) -I ./ $(CLIENT_OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -L $(LIBFTPRINTF_DIR) -l $(LIBFTPRINTF_NAME) -o $@

$(OBJ_DIR)/%.o : %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(LIBFTPRINTF_DIR) -c $< -o $@ -g

$(LIBFT)	:
	make -C $(LIBFT_DIR) all

$(LIBFTPRINTF)	:
	make -C $(LIBFTPRINTF_DIR) all

clean :
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBFTPRINTF_DIR) clean

fclean : clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBFTPRINTF_DIR) fclean

re	:
	make fclean
	make all

.PHONY : all clean fclean re bonus
