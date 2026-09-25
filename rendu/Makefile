# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/25 13:40:41 by marhuber          #+#    #+#              #
#    Updated: 2026/09/25 13:52:39 by marhuber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Names of the executables
NAME = miniRT

# Compiling
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Name of all sources files to be passed to the CC command
MY_SOURCES = \
	src/main.c \
	src/utils/lists1.c src/utils/lists2.c \
	src/utils/get_next_line.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

## Rules to compile
# Rule that gets called by default 
$(NAME): $(MY_OBJECTS)
	$(CC) $^ -o $(NAME)
# An implicit rule creates the objects using CFLAGS

all: $(NAME)

## Rules to clean up
clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.SECONDARY: $(MY_OBJECTS)