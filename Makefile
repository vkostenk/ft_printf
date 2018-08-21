# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/06 12:46:10 by vkostenk          #+#    #+#              #
#    Updated: 2018/08/21 13:24:15 by vkostenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

LIB = libft.a

SRCS = ft_printf.c\
			 all_flags.c\
			 flags.c\
			 func_choze.c\
			 ft_print_str.c\
			 ft_print_nbr.c\
			 ft_print_char.c\
			 ft_print_hex.c\
			 ft_print_octal.c\
			 ft_print_ptr.c\
			 ft_print_wstr.c\
			 ft_print_unbr.c\
			 ft_uint_count.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(CC) $(FLAGS) -c $(SRCS) -I $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT)/*.o
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/$(LIB)

re: fclean all
