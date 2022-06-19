#		asalek (Ayoub Salek) messalih (Mustapha essalih)

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
SEGFAULT = -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
SRC = main.c check_path.c excute_cmd.c built_in.c libft.c create_linked_list.c check_syntax_cmd.c \
quotes.c pipee.c pipe.c check_quots.c built_in_additional.c echo.c split_pipe.c \
check_pipe.c free.c slice_parss_red.c handle_redirecion.c reverse_cmd.c collect_cmd.c complete_cmd.c \
rreverse_cmd_2.c quots_red.c quots_.c redirect_files.c open_files_1.c open_files_2.c herdoc_handle.c if_is_bult.c \
execut_built.c red_execut.c

OBJ = $(SRC:.c=.o)
CFLAGS := -g -I /goinfre/${USER}/.brew/opt/readline/include -D BUFFER_SIZE=1
LDFLAGS := -L /goinfre/${USER}/.brew/opt/readline/lib

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${WHITE}░M░i░n░i░ ░S░h░e░l░l░\033[0m"
	@make -C libft/
	@$(CC) -fsanitize=address  -L $(shell brew --prefix readline)/lib -lreadline libft/libft.a $^ -o $@
	@echo "${GREEN}all${RESET}"
#	@clear

%.o: %.c
	@$(CC) -I $(shell brew --prefix readline)/include -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make clean -C libft
	@echo "${RED}clean${RESET}"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@echo "${YELLOW}fclean${RESET}"

re: fclean all
	@echo "${PURPLE}re${RESET}"

.PHONY: re all clean fclean
