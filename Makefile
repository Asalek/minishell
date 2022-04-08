#░M░i░n░i░ ░S░h░e░l░l░
ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c check_path.c excute_cmd.c built_in.c libft.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[92m░M░i░n░i░ ░S░h░e░l░l░\033[0m"
	@make -C libft/
	@$(CC) -lreadline $^ libft/libft.a -o $@
	@echo "${WHITE}Make All${RESET}"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: re all clean fclean