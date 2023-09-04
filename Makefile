# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akunegel <akunegel@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:10:32 by akunegel          #+#    #+#              #
#    Updated: 2023/07/31 14:10:34 by akunegel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

CC = cc
CCFLAGS = cc -Wall -Werror -Wextra

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
		${CCFLAGS} ${OBJS_SERVER} libft/libft.a -o ${SERVER}
		${CCFLAGS} ${OBJS_CLIENT} libft/libft.a -o ${CLIENT}

$(LIBFT):
		${MAKE} -C ./libft

bonus: ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS} ${LIBFT}
		${CCFLAGS} ${OBJS_SERVER_BONUS} libft/libft.a -o ${SERVER}
		${CCFLAGS} ${OBJS_CLIENT_BONUS} libft/libft.a -o ${CLIENT}

clean:	
		$(MAKE) clean -C ./libft
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(SERVER) $(CLIENT)

re:	fclean all
