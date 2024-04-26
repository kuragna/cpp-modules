NAME		= a.out
CPPFLAGS	= -Wall -Werror -Wextra -std=c++11 #-std=c++98
SRC			= main.cpp Bureaucrat.cpp

all: $(NAME)

$(NAME): $(SRC)
	c++ -o $@ $(CPPFLAGS) $^

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
