# Program name
NAME = push_swap

# Directories
LIBFT = ./libft/libft.a
INC = inc/
SRC_DIR = src/
UTILS_DIR = utils/
OBJ_DIR = obj/

# Files
COMMANDS_DIR_FILES =	$(SRC_DIR)/commands/push.c\
						$(SRC_DIR)/commands/rotate.c\
						$(SRC_DIR)/commands/rrotate.c\
						$(SRC_DIR)/commands/swap.c\


PUSH_DIR_FILES =	$(SRC_DIR)/push/errors.c \
					$(SRC_DIR)/push/stack_init.c \
					$(SRC_DIR)/push/sorting.c\
					$(SRC_DIR)/main.c \

UTILS_FILES =		$(UTILS_DIR)/stack_utils.c \
					$(UTILS_DIR)/commands_utils.c\

# concatenate all source files
SRC = $(PUSH_DIR_FILES) $(UTILS_FILES) $(COMMANDS_DIR_FILES)

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC)) # Pq n é: OBJ = $(patsubst %.c, %.o, $(SRC))

# Compiler & cflags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules
all:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC) $(OBJ) $(LIBFT) -o $(NAME)
$(LIBFT):
	@make -C ./libft
$(OBJ_DIR)%.o:  $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@rm -f -r $(OBJ_DIR)
	@make clean -C ./libft

fclean:	clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re:		fclean all

.PHONY: all clean fclean re

