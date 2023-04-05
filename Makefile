# Directories
SRC_DIR      = src/
OBJ_DIR      = obj/
LIB_DIR      = libft/
PRINTF_DIR   = ft_printf/

# Files
COMMON_SRC   = ini_functions.c operations.c operations2.c \
               indexing.c operations3.c radix_sort.c util_functions.c \
               error.c small_sort.c small_sort2.c
PUSH_SWAP_SRC = pushswap.c $(COMMON_SRC)
CHECKER_SRC  = checker.c $(COMMON_SRC)

PUSH_SWAP_SRCS  = $(addprefix $(SRC_DIR), $(PUSH_SWAP_SRC))
CHECKER_SRCS   = $(addprefix $(SRC_DIR), $(CHECKER_SRC))

PUSH_SWAP_OBJS  = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_SRC:.c=.o))
CHECKER_OBJS   = $(addprefix $(OBJ_DIR), $(CHECKER_SRC:.c=.o))

LIBFT        = cd $(LIB_DIR) && make
FT_PRINTF    = cd $(PRINTF_DIR) && make
LIB          = $(LIB_DIR)libft.a
PRINTF       = $(PRINTF_DIR)libftprintf.a

# Compiler options
CC           = gcc
CFLAGS       = -Wall -Wextra -Werror -g -fsanitize=address
INCLUDE      = -I include

# Executable names
PUSH_SWAP_NAME = push_swap
CHECKER_NAME = checker

# Colors
BOLD_PURPLE  = \033[1;35m
BOLD_CYAN    = \033[1;36m
BOLD_YELLOW  = \033[1;33m
BOLD_GREEN   = \033[1;32m
NO_COLOR     = \033[0m

# Messages
COMP_START  = @echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"
READY       = @echo "\n📟 $(BOLD_GREEN)$(PUSH_SWAP_NAME) and $(CHECKER_NAME) are ready!\n"
CLEANED     = @echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED    = @echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# Rules
all: $(OBJ_DIR) $(PUSH_SWAP_NAME) $(CHECKER_NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJS)
	$(COMP_START)
	$(LIBFT)
	$(FT_PRINTF)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(LIB) $(PRINTF) -o $(PUSH_SWAP_NAME)
	$(READY)

$(CHECKER_NAME): $(CHECKER_OBJS)
	$(COMP_START)
	$(LIBFT)
	$(FT_PRINTF)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIB) $(PRINTF) -o $(CHECKER_NAME)
	$(READY)

clean:
	@rm -rf $(OBJ_DIR)
	@cd $(LIB_DIR) && make clean
	@cd $(PRINTF_DIR) && make clean
	$(CLEANED)

fclean: clean
	@rm -rf $(PUSH_SWAP_NAME)
	@rm -rf $(CHECKER_NAME)
	@cd $(LIB_DIR) && make fclean
	@cd $(PRINTF_DIR) && make fclean
	$(FCLEANED)

re: fclean all

.PHONY:
