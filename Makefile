NAME= lem_in

SRC_PATH= src
SRC_NAME= ft_add_links.c	ft_alloc_big_tab.c	ft_check_nbr.c\
		  ft_error_function.c ft_hash_function.c  ft_prime.c\
		  ft_stock_file.c     ft_stock_rooms.c  

HDR_PATH= includes
HDR_NAME= ft_lem_in.h

LIB_PATH= libftprintf
LIB= libftprintf.a

OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)

SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))
OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# **************************************************************************** #

CW=	gcc
CFLAGES= -Wall -Wextra -Werror

LD_FLAGS= -L$(LIB_PATH)
LD_LIBS= -l$(patsubst lib%.a,%, $(LIB))

HDR_FLAGS= -I$(HDR_PATH)

# **************************************************************************** #

all: lib $(NAME) 


$(NAME): $(LIB_PATH)/$(LIB) $(OBJ)
	@$(CW)  $(LD_FLAGS) $(LD_LIBS) $(CFLAGS) $(OBJ) -o $@
	@ echo "\033[1;32m>> lem-in binary is ready ;)\033[0m"

lib:
	@make -sC $(LIB_PATH)

$(LIB_PATH)/$(LIB): lib

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HDR)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CW) $(CFLAGS) $(HDR_FLAGS) -o $@ -c $<

clean:
	@rm -fr $(OBJ)
	@rm -fr $(OBJ_PATH) 2> /dev/null || true
	@make -C libftprintf clean
	@echo "\033[1;33m>> Lem-in object files deleted.\033[0m" 

fclean:
	@rm -fr $(OBJ)
	@rm -fr $(NAME)
	@rm -fr $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[1;33m>> Lem-in object files deleted.\033[0m" 
	@make -C libftprintf fclean
	@echo "\033[0;31m>> Lem-in binary deleted.\033[0m" 

re: fclean all
