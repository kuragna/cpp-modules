NAME		= a.out
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
SRC			= main.cpp Bureaucrat.cpp

all: $(NAME)

$(NAME): $(SRC) Bureaucrat.hpp
	c++ -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
