# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouita <csouita@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 21:09:48 by csouita           #+#    #+#              #
#    Updated: 2024/04/19 18:51:23 by csouita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = cc

SRC = loot.c
OBJC = client.o $(SRC:.c=.o)
OBJS = server.o $(SRC:.c=.o)
OBJCB = client_bonus.o $(SRC:.c=.o)
OBJSB = server_bonus.o $(SRC:.c=.o)

all: client server

client: client.c $(OBJC)
	        $(CC) $(CFLAGS) $(OBJC) -o client

server: server.c $(OBJS)
	        $(CC) $(CFLAGS) $(OBJS) -o server

bonus: client_bonus server_bonus

client_bonus: client_bonus.c $(OBJCB)
	        $(CC) $(CFLAGS) $(OBJCB) -o client_bonus

server_bonus: server_bonus.c $(OBJSB)
	        $(CC) $(CFLAGS) $(OBJSB) -o server_bonus

clean:
	        rm -rf loot.o client.o server.o server_bonus.o client_bonus.o

fclean: clean
	        rm -rf client server client_bonus server_bonus

re: fclean all bonus

.SECONDARY:
