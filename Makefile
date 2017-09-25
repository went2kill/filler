# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/08 19:01:12 by yrobotko          #+#    #+#              #
#    Updated: 2017/08/24 18:34:22 by yrobotko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

G = gcc

FLAG = -Wall -Wextra -Werror

SRC =   filler.c \
		part1f.c \
		part2f.c \
		part3f.c \

OBJ = $(SRC:.c=.o)

DEL = rm -f

LIB = libft/libft.a

all: $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft/ re
	gcc $(FLAG) $(LIB) $(OBJ) -o $(NAME) 
%.o: %.c
	$(G) $(CFLAGS) -c -o $@ $<
clean:
	$(DEL) $(OBJ)
	$(DEL) libft/*.o
fclean: clean
	$(DEL) $(NAME)
	$(DEL) libft/libft.a
re:	fclean
	make
