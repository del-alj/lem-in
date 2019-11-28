# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-alj <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 17:01:57 by del-alj           #+#    #+#              #
#    Updated: 2019/11/28 12:37:52 by del-alj          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRC =	ft_lem_in.c\
		ft_stock_file.c\
		ft_check_nbr.c\
		t_read_n_ants.c\
		ft_read_room.c\


SRC_LIBFT = libft/ft_atoi.c\
			libft/ft_bzero.c\
			libft/ft_isalnum.c\
			libft/ft_isalpha.c\
			libft/ft_isascii.c\
			libft/ft_isdigit.c\
			libft/ft_isprint.c\
			libft/ft_itoa.c\
			libft/ft_memalloc.c\
			libft/ft_memccpy.c\
			libft/ft_memchr.c\
			libft/ft_memcmp.c\
			libft/ft_memcpy.c\
			libft/ft_memdel.c\
			libft/ft_memmove.c\
			libft/ft_memset.c\
			libft/ft_putchar.c\
			libft/ft_putstr.c\
			libft/ft_putendl.c\
			libft/ft_putendl_fd.c\
			libft/ft_putchar_fd.c\
			libft/ft_putnbr.c\
			libft/ft_putnbr_fd.c\
			libft/ft_putstr_fd.c\
			libft/ft_strcat.c\
			libft/ft_strchr.c\
			libft/ft_strcmp.c\
			libft/ft_strclr.c\
			libft/ft_strcpy.c\
			libft/ft_strequ.c\
			libft/ft_strnequ.c\
			libft/ft_strdel.c\
			libft/ft_strdup.c\
			libft/ft_striter.c\
			libft/ft_striteri.c\
			libft/ft_strjoin.c\
			libft/ft_strlcat.c\
			libft/ft_strlen.c\
			libft/ft_strmap.c\
			libft/ft_strmapi.c\
			libft/ft_strncat.c\
			libft/ft_strnew.c\
			libft/ft_strncmp.c\
			libft/ft_strncpy.c\
			libft/ft_strnstr.c\
			libft/ft_strrchr.c\
			libft/ft_strstr.c\
			libft/ft_strsub.c\
			libft/ft_strsplit.c\
			libft/ft_strtrim.c\
			libft/ft_tolower.c\
			libft/ft_toupper.c\
			libft/ft_lstnew.c\
			libft/ft_lstdelone.c\
			libft/ft_lstdel.c\
			libft/ft_lstadd.c\
			libft/ft_lstiter.c\
			libft/ft_lstmap.c\
			libft/ft_ramstr.c\
			libft/ft_lstadd_next.c\
			libft/ft_strndup.c\
			libft/ft_swapchar.c\
			libft/ft_print.c\
			libft/ft_lenlist.c\
			libft/ft_lst_del_node.c\
			libft/get_next_line.c

NAME = lem_in

NAME_LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

INCLUDESLIB = libft/libft.h
INCLUDESGNL = libft/get_next_line.h
INCLUDESLM = ft_lem_in.h

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ_LIBFT)
	@ar rc $(NAME_LIBFT) $(OBJ_LIBFT)
	$(CC) -Wall -Werror -Wextra -o $(NAME) $(OBJ) $(NAME_LIBFT)

clean :
	@rm -f $(OBJ)
	@rm -f $(OBJ_LIBFT)
fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_LIBFT)
re : fclean all
