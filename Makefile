NAME = push_swap

BNAME = checker

SRC = error.c main.c my_spliter.c push_swap.c  push_swap_utiles_4.c push_swap_utiles_1.c push_swap_utiles_2.c push_swap_utiles_3.c rules_1.c rules_2.c rules_3.c rules_utils_1.c rules_utils_2.c split_args.c writer.c error_utils.c 

BSRC = error.c checker.c my_spliter.c push_swap.c  push_swap_utiles_4.c push_swap_utiles_1.c push_swap_utiles_2.c push_swap_utiles_3.c rules_1_bonus.c rules_2_bonus.c rules_3_bonus.c rules_1.c rules_2.c rules_3.c rules_utils_1.c rules_utils_2.c split_args.c writer.c error_utils.c checker_utils.c 

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

RED=$(echo -e "\033[0;31m")

YELLOW=$(echo -e "\033[0;33m")

GREEN=$(echo -e "\033[0;32m")

BLUE=$(echo -e "\033[0;34m")

END=$(echo -e "\033[0m")

CFLAGS = -Wall -Wextra -Werror

B = bonus

CC = cc

AR = ar rcs

RM = rm -rf

all : make_libft $(NAME) done

bonus : $(BNAME)

make_libft :
	@echo "\033[1;91m"
	@echo "                **********************"
	@echo "                *                    *"
	@echo "                *       libft        *"
	@echo "                *                    *"
	@echo "                **********************"

	@cd libft/ && make 
#	@make clean
	@cd ..

norm :
	 @echo  "\033[0;32m" && norminette


$(NAME) : $(OBJ) push_swap.h 
	@echo  "\033[0;33m"
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)  

$(BNAME) : $(BOBJ) push_swap.h
	make -C libft
	$(CC) $(CFLAGS) $(BOBJ) libft/libft.a -o $(BNAME)

clean : clean_libft
	@echo  "\033[0;31m"
	$(RM) $(OBJ)
	$(RM) $(BOBJ)

clean_libft :
	@cd libft/ && make clean
	@cd ..
fclean : clean clean_libft
	$(RM) $(NAME)
	$(RM) $(BNAME)
	rm -rf libft/libft.a
	@echo  "\033[0;33m everything is clean now :)"

re : fclean all

re_bonus : fclean bonus

done:
	@echo  "\033[0;32m"
	@echo "                ****-------------------------------------------------------------------****"   
	@echo "                ***---------------------------------------------------------------------***"   
	@echo "                |||                                                                     |||"  
	@echo "                |||     db    8888b.  8b    d8    db    88b 88 .dP*Y8    db    88**Yb   |||"  
	@echo "                |||    dPYb    8I  Yb 88b  d88   dPYb   88Yb88 *Ybo.    dPYb   88__dP   |||"  
	@echo "                |||   dP__Yb   8I  dY 88YbdP88  dP__Yb  88 Y88 o.*Y8b  dP__Yb  88*Yb    |||"  
	@echo "                |||  dP****Yb 8888Y*  88 YY 88 dP****Yb 88  Y8 8bodP* dP****Yb 88  Yb   |||"  
	@echo "                |||                                                                     |||"  
	@echo "                ***---------------------------------------------------------------------***"  
	@echo "                ****-------------------------------------------------------------------****"  

