<<<<<<< HEAD
#TARGET
NAME = push_swap

#ARGUMENTS
CC = gcc
FLAGS = -Wall -Werror -Wextra 
#SEG = -fsanitize=address -g

#PUSH_SWAP FILES
SRC_PATH = ./srcs/
SRC =	commands \
		error_handling \
		execution1 \
		execution2 \
		execution3 \
		init_nodes \
		main \
		sort \
		sort2 \
		stack_utils \
		stack_utils2
C_FILES = $(addprefix $(SRC_PATH), $(SRC:=.c))
OBJ = $(addprefix $(SRC_PATH), $(SRC:=.o))

#LIBFT
LBFT_PATH = ./libft/
LBFT = 	ft_split \
		ft_atoi \
		ft_printf \
		ft_print_utilities \
		ft_printf_utils 
		

LBFT_FILES = $(addprefix $(LBFT_PATH), $(LBFT:=.c))
LBFT_OBJ = $(addprefix $(LBFT_PATH), $(LBFT:=.o))

#RULES
all: $(NAME)

$(NAME): $(OBJ) $(LBFT_OBJ)
	@ $(CC) $(FLAGS) $(OBJ) $(LBFT_OBJ) -o $(NAME)

.c.o:
	@ $(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(LBFT_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
=======
# NAME				= push_swap

# # Directories
# PRINTF				= ./Printf/printf.a
# INC					= inc/
# SRC_DIR				= srcs/
# OBJ_DIR				= obj/

# # Compiler and CFlags
# CC					= gcc
# CFLAGS				= -Wall -Werror -Wextra -I 
# RM					= rm -f

# # Source Files
# COMMANDS_DIR		=	$(SRC_DIR)commands/commands.c \
# 						$(SRC_DIR)commands/execution1.c \
# 						$(SRC_DIR)commands/execution2.c \
# 						$(SRC_DIR)commands/execution3.c \

# PARSING_DIR			=	$(SRC_DIR)parsing/error_handling.c\

# PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/init_nodes.c \
# 						$(SRC_DIR)push_swap/sort.c \
# 						$(SRC_DIR)push_swap/sort2.c \
# 						$(SRC_DIR)push_swap/main.c \
# 						$(SRC_DIR)push_swap/split.c \
# 						$(SRC_DIR)push_swap/stack_utils.c \
# 						$(SRC_DIR)push_swap/stack_utils2.c \

# # Concatenate all source files
# SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# # Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
# OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# # Build rules
# start:				
# 					@make all

# $(PRINTF):
# 					@make -C ./printf

# all: 				$(NAME)

# $(NAME): 			$(OBJ) $(PRINTF)
# 					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# # Compile object files from source files
# $(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
# 					@mkdir -p $(@D)
# 					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# clean:
# 					@$(RM) -r $(OBJ_DIR)
# 					@make clean -C ./printf

# fclean: 			clean
# 					@$(RM) $(NAME)
# 					@$(RM) $(PRINTF)

# re: 				fclean all

# # Phony targets represent actions not files
# .PHONY:				start all clean fclean re


NAME = push_swap

CC = gcc -c

FLAGS = -Wall -Werror -Wextra

SRC_PART			 =	$(SRC_DIR)commands/commands.c \
 						$(SRC_DIR)commands/execution1.c \
 						$(SRC_DIR)commands/execution2.c \
 						$(SRC_DIR)commands/execution3.c \
						$(SRC_DIR)parsing/error_handling.c\
						$(SRC_DIR)Push_swap/init_nodes.c \
						$(SRC_DIR)Push_swap/sort.c \
						$(SRC_DIR)Push_swap/sort2.c \
						$(SRC_DIR)Push_swap/main.c \
						$(SRC_DIR)Push_swap/split.c \
						$(SRC_DIR)Push_swap/stack_utils.c \
						$(SRC_DIR)Push_swap/stack_utils2.c \

OBJ_PART = $(SRC_PART:.c=.o)

RM = rm -f

HEAD = ./inc/push_swap.h

.c.o : $(SRCS)
	${CC} ${FLAGS} -c -o $@ $^

all : $(NAME)

$(NAME) : $(OBJ_PART) $(HEAD)
	@$(CC) $(SRC_PART) $(FLAGS)

fclean : clean
	$(RM) $(NAME) $(OBJ_PART)

re : fclean all

.PHONY : all clean fclean re
>>>>>>> ddd1fe897386cc7b8764a51e4437576b741e68f1
