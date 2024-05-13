NAME		= a.out
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 -ggdb
SRC			= main.cpp Bureaucrat.cpp Form.cpp

all: $(NAME)

$(NAME): $(SRC) Bureaucrat.hpp Form.hpp
	c++ -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
