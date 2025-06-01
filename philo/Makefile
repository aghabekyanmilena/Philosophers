NAME = philo
SRC_DIR = src
INC_DIR = includes

SRC = $(SRC_DIR)/action.c $(SRC_DIR)/check_die.c $(SRC_DIR)/checkings.c $(SRC_DIR)/initialization.c \
	$(SRC_DIR)/main.c $(SRC_DIR)/one_philo.c $(SRC_DIR)/routine.c $(SRC_DIR)/timing.c \
	$(SRC_DIR)/utils.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) #-fsanitize=address
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INC_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re