#TARGET
NAME = push_swap

#ARGUMENTS
CC = gcc
FLAGS = -Wall -Werror -Wextra 
# SEG = -fsanitize=address -g

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
		ft_atol \
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
