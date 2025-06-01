NAME = philo_bonus
SRC_DIR = src
INC_DIR = includes

SRC = $(SRC_DIR)/bonus_checkings.c $(SRC_DIR)/bonus_init.c $(SRC_DIR)/bonus_one_philo.c $(SRC_DIR)/bonus_timing.c \
		$(SRC_DIR)/bonus_utils.c $(SRC_DIR)/main.c $(SRC_DIR)/bonus_free.c $(SRC_DIR)/bonus_actions.c \
		$(SRC_DIR)/bonus_create.c

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