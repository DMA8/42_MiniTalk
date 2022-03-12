# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syolando <syolando@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 13:58:56 by syolando          #+#    #+#              #
#    Updated: 2022/02/15 18:20:31 by syolando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

GCC = gcc
CFLAGS = -Wall -Werror -Wextra

SOURCE_SERVER = server.c \

SOURCE_CLIENT = client.c \

SOURCE_UTILS = utils.c \

SOURCE_SERVER_BONUS = server_bonus.c \

SOURCE_CLIENT_BONUS = client_bonus.c \

SOURCE_UTILS_BONUS = utils_bonus.c \


OBJS_SERVER = $(SOURCE_SERVER:.c=.o)
OBJS_CLIENT = $(SOURCE_CLIENT:.c=.o)
OBJS_UTILS = $(SOURCE_UTILS:.c=.o)

OBJS_SERVER_BONUS = $(SOURCE_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SOURCE_CLIENT_BONUS:.c=.o)
OBJS_UTILS_BONUS = $(SOURCE_UTILS_BONUS:.c=.o)

all:  $(SERVER) $(CLIENT) 

$(SERVER): $(OBJS_SERVER) $(OBJS_UTILS) minitalk.h
	@$(GCC) $(CFLAGS) $(OBJS_SERVER) $(OBJS_UTILS) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(OBJS_UTILS) minitalk.h
	@$(GCC) $(CFLAGS) $(OBJS_CLIENT) $(OBJS_UTILS) -o $(CLIENT)

$(SERVER_BONUS): $(OBJS_SERVER_BONUS) $(OBJS_UTILS_BONUS) minitalk_bonus.h
	@$(GCC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(OBJS_UTILS_BONUS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(OBJS_UTILS_BONUS) minitalk_bonus.h
	@$(GCC) $(CFLAGSB) $(OBJS_CLIENT_BONUS) $(OBJS_UTILS_BONUS) -o $(CLIENT_BONUS)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_UTILS) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS) $(OBJS_UTILS_BONUS)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_UTILS) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS) $(OBJS_UTILS_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus