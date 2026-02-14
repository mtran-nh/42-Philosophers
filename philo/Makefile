# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 11:06:46 by mtran-nh          #+#    #+#              #
#    Updated: 2026/02/14 12:31:04 by mtran-nh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

CC = cc 
CFLAGS = -Wall -Wextra -Werror -pthread 

SRC_DIR = src
INCLUDES = -I includes/

SRC = 	$(SRC_DIR)/utils.c \
		$(SRC_DIR)/string.c \
		$(SRC_DIR)/get_data.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/action.c \
		$(SRC_DIR)/simulation.c \
		$(SRC_DIR)/main.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
