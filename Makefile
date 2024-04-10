# Program name
NAME = push_swap
NAME_BONUS = checker

# Directories
LIBFT = ./libft/libft.a
INC = inc/
SRC_DIR = src/
UTILS_DIR = utils/
OBJ_DIR = obj/
BONUS_DIR = bonus/
BONUS_OBJ_DIR = bonus_obj/

# Push Files
COMMANDS_DIR_FILES =	$(SRC_DIR)/commands/push.c\
						$(SRC_DIR)/commands/rotate.c\
						$(SRC_DIR)/commands/rrotate.c\
						$(SRC_DIR)/commands/swap.c\


PUSH_DIR_FILES =	$(SRC_DIR)push/errors.c \
					$(SRC_DIR)push/stack_init.c \
					$(SRC_DIR)push/sorting.c\
					$(SRC_DIR)push/init_nodes.c\
					$(SRC_DIR)push/move_nodes.c

UTILS_FILES =		$(UTILS_DIR)/stack_utils.c \
					$(UTILS_DIR)/errors_sinit_utils.c \
					$(UTILS_DIR)/sorting_utils.c\

# Bonus files

BONUS_FILES =	$(BONUS_DIR)/checker.c

# concatenate all push source files
SRC = $(PUSH_DIR_FILES) $(UTILS_FILES) $(COMMANDS_DIR_FILES) $(SRC_DIR)main.c \

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

# bonus obj

SRC_BONUS = $(BONUS_FILES) $(PUSH_DIR_FILES) $(UTILS_FILES) $(COMMANDS_DIR_FILES)

OBJ_BONUS = $(patsubst $(BONUS_FILES)%.c, $(OBJ_BONUS_DIR)%.o, $(SRC_BONUS))

# Compiler & cflags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules
all:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC) $(OBJ) $(LIBFT) -o $(NAME)
$(LIBFT):
	@make -C ./libft
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJ_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)
#$(LIBFT):
#	@make -C ./libft
$(BONUS_OBJ_DIR)%.o: $(BONUS_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@rm -f -r $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@make clean -C ./libft

fclean:	clean
		rm -f $(NAME)
		rm -f $(NAME_BONUS)
		rm -f $(LIBFT)

re:		fclean all

.PHONY: all bonus clean fclean re

