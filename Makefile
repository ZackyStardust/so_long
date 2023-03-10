# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 18:35:35 by fpereira          #+#    #+#              #
#    Updated: 2023/01/27 14:27:47 by fpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g -I./includes -I/usr/include -Imlx_linux
MLXFLAGS	= -Lmlx_linux -L/usr/lib -Imlx_linux -lmlx_Linux -lXext -lX11 -lm -lz
MLX_LINUX	= -O3
RM			= rm -f

NAME		= so_long
OBJDIR		= obj
SRCS		= $(wildcard srcs/*.c srcs/*/*.c)
OBJS		= $(patsubst srcs/%.c,$(OBJDIR)/%.o,$(SRCS))

all:$(NAME)	

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(MLX_LINUX) $(OBJS) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: srcs/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(MLX_LINUX) -c $< $(MLXFLAGS) -o $@

clean:
			$(RM) $(OBJS)
#			$(OBJS_B)

fclean:		clean
			$(RM) $(NAME)
#			$(NAME_B)

re:			fclean all