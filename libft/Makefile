# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admansar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 18:33:04 by admansar          #+#    #+#              #
#    Updated: 2023/03/30 01:01:01 by admansar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRC = get_next_line.c get_next_line_utils.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memcmp.c ft_strnstr.c \
ft_memchr.c ft_strncmp.c ft_strdup.c ft_calloc.c ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
ft_putadres.c ft_putnbr_hexa.c ft_putstr.c ft_printf.c ft_putchar.c ft_putnbr_hexa_up.c ft_printf.h	ft_putnbr.c	ft_putnbr_ui.c  \

BSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

AR = ar rcs

RM = rm -rf


all : $(NAME)

$(NAME) : $(OBJ)
	echo "\033[0;34m"
	$(AR) $(NAME) $(OBJ)

bonus : $(BOBJ)
	$(AR) $(NAME) $(BOBJ) 

clean : 
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all

