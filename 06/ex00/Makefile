NAME		= convert
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 -ggdb -fsanitize=address #-fsanitize=undefined
SRC			= main.cpp ScalarConverter.cpp Data.cpp

all: $(NAME)

$(NAME): $(SRC) ScalarConverter.hpp Data.hpp
	c++ -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
