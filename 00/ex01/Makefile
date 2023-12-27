NAME	= phonebook
CPP		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98 -fsanitize=address
RM		= rm -fr

SRC		= PhoneBook.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CPP) -o $@ $(FLAGS) $^

fclean:
	$(RM) $(NAME)
re: fclean all

.PHONY: all fclean re

