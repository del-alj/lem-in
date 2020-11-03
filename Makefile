NAME= lem-in

SRC_PATH= src
SRC_NAME= ft_main.c	ft_error_function.c	ft_balance.c \
		  ft_max.c	ft_insert_node.c	save_info.c \
		  parse.c	ft_add_edge.c		ft_dfs.c \
		  bfs.c  	ft_make_group.c 	ft_simple_lstdel.c \
		  ft_pass_ants.c				ft_print_ant.c

HDR_PATH= includes
HDR_NAME= ft_lem_in.h

LIB_PATH= libft
LIB= libft.a

OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)

SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))
OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# **************************************************************************** #

COMP=	gcc
CFLAGES= -Wall -Wextra -Werror

LD_FLAGS= -L$(LIB_PATH)
LD_LIBS= -l$(patsubst lib%.a,%, $(LIB))

HDR_FLAGS= $(HDR_PATH)

# **************************************************************************** #

all: lib $(NAME) 


$(NAME): $(LIB_PATH)/$(LIB) $(OBJ)
	@$(COMP) -g $(LD_FLAGS) $(LD_LIBS) $(CFLAGS) $(OBJ) -o $@
	@ echo "\033[1;34m>>\033[0m $(NAME)\033[1;32m binary is ready.\033[0m"

lib:
	@make -sC $(LIB_PATH)

$(LIB_PATH)/$(LIB): lib

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HDR)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(COMP) $(CFLAGS) -I $(HDR_FLAGS) -o $@ -c $<

clean:
	@rm -fr $(OBJ)
	@rm -fr $(OBJ_PATH) 2> /dev/null || true
	@make -C $(LIB_PATH) clean
	@echo "\033[1;34m>>\033[0m $(NAME)\033[1;33m object files deleted.\033[0m" 

fclean:
	@make -C $(LIB_PATH) fclean
	@rm -fr $(OBJ)
	@rm -fr $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[1;34m>>\033[0m $(NAME)\033[1;33m object files deleted.\033[0m" 
	@rm -fr $(NAME)
	@echo "\033[0;34m>>\033[0m $(NAME)\033[0;31m binary deleted.\033[0m" 

re: fclean all
