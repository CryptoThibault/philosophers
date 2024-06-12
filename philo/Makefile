NAME = philo
FILES = main.c \
	ft_atoi.c \
	fill_table.c \
	fill_philosophers.c \
	table_error.c \
	free_table.c \
	philo.c \
	philosopher_life.c \
	monitor_philosophers.c \
	get_timestamp_ms.c
FLAGS = -Wall -Wextra -Werror

$(NAME):
	cc $(FLAGS) -o $@ $(FILES)
all: $(NAME)

clean:
	rm -f *.out
fclean: clean
	rm  -f $(NAME) $(BONUS)
re: fclean  all
