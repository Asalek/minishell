NAME = minishell

SRC = main.c check_path.c libft.c excute_cmd.c built_in.c


all: $(NAME)

$(NAME): $(SRC) minishell.h
	gcc  $(SRC) -o $@ -lreadline

clean:
	rm -rf $(NAME)


re: fclean all