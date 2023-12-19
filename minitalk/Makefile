# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:47:45 by jtollena          #+#    #+#              #
#    Updated: 2023/12/19 13:20:10 by jtollena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CSOURCES = srcs/client/main.c
SSOURCES = srcs/server/main.c

COBJECTS = $(CSOURCES:.c=.o)
SOBJECTS = $(SSOURCES:.c=.o)
INCLUDES = includes
FLAGS =  #-Wall -Wextra -Werror

%.o: %.c
	gcc $(FLAGS) -Ilibft -I $(INCLUDES) -c $< -o $@

all: $(CLIENT) $(SERVER)

$(SERVER): $(SOBJECTS) $(SINCLUDES)
	make -C libft/
	gcc $(SOBJECTS) -Llibft -lft -o $(SERVER)

$(CLIENT): $(COBJECTS) $(CINCLUDES)
	make -C libft/
	gcc $(COBJECTS) -Llibft -lft -o $(CLIENT)

clean:
	rm $(COBJECTS)
	rm $(SOBJECTS)
#	make -C libft/ clean

fclean:
	rm $(COBJECTS)
	rm $(SOBJECTS)
	rm $(CLIENT)
	rm $(SERVER)
	make -C libft/ fclean

re: fclean $(CLIENT) $(SERVER)

.PHONY: re fclean clean all