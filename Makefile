NAME = push_swap

SRC = error.c main.c my_spliter.c push_swap.c push_swap_utiles_1.c push_swap_utiles_2.c push_swap_utiles_3.c rules_1.c rules_2.c rules_3.c rules_utils_1.c rules_utils_2.c split_args.c writer.c error_utils.c 

OBJ = $(SRC:.c=.o)

LIBFT_SRC = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c \
libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_memcmp.c libft/ft_strnstr.c \
 libft/ft_memchr.c libft/ft_strncmp.c libft/ft_calloc.c libft/ft_atoi.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_itoa.c libft/ft_strmapi.c \
libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_split.c \
 libft/ft_putadres.c libft/ft_putnbr_hexa.c libft/ft_putstr.c libft/ft_printf.c libft/ft_putchar.c libft/ft_putnbr_hexa_up.c libft/ft_putnbr.c libft/ft_putnbr_ui.c

RED=$(echo "\033[0;31m")

YELLOW=$(echo "\033[0;33m")

GREEN=$(echo "\033[0;32m")

BLUE=$(echo "\033[0;34m")

END=$(echo "\033[0m")

CFLAGS = -Wall -Wextra -Werror

CC = cc

AR = ar rcs

RM = rm -rf

all :norm make_libft $(NAME) done 

make_libft :
	@echo "\033[1;91m"
	@echo "                **********************"
	@echo "                *                    *"
	@echo "                *       libft        *"
	@echo "                *                    *"
	@echo "                **********************"

	@echo "\033[0;33m" && cd libft/ && make 
	@cd ..

norm :
	 @echo "\033[0;32m" && norminette


$(NAME) : $(SRC) 
	@echo "\033[0;36m"
	@echo -e "\e[1m\e[0m"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_SRC) -o $(NAME) 

clean :
	@echo "\033[0;31m"
	$(RM) $(OBJ)

clean_libft :
	@cd libft/ && make fclean
	@cd ..
fclean : clean clean_libft
	$(RM) $(NAME)
	@echo "\033[0;33m everything is clean now :)"

re : fclean all

done:
	@echo "\033[1;91m"
	@echo "                *****--------------------------------------------------------------------****"
	@echo "                ****----------------------------------------------------------------------***"
	@echo "                ***-----------------------------------------------------------------------***"
	@echo "                |||                                                                       |||"
	@echo "                |||                                                                       |||"
	@echo "                |||                                                                       |||"
	@echo "                |||                                                                       |||"
	@echo "                |||      db    8888b.  8b    d8    db    88b 88 .dP*Y8    db    88**Yb    |||"
	@echo "                |||     dPYb    8I  Yb 88b  d88   dPYb   88Yb88 *Ybo.    dPYb   88__dP    |||"
	@echo "                |||    dP__Yb   8I  dY 88YbdP88  dP__Yb  88 Y88 o.*Y8b  dP__Yb  88*Yb     |||"
	@echo "                |||   dP****Yb 8888Y*  88 YY 88 dP****Yb 88  Y8 8bodP* dP****Yb 88  Yb    |||"
	@echo "                |||                                                                       |||"
	@echo "                |||                                                                       |||"
	@echo "                |||                                                                       |||"
	@echo "                |||                                                                       |||"
	@echo "                ***-----------------------------------------------------------------------***"
	@echo "                ****---------------------------------------------------------------------****"
	@echo "                *****-------------------------------------------------------------------*****"

