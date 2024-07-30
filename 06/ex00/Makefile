NAME		= convert
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 -ggdb -fsanitize=address
SRC			= main.cpp  Data.cpp ScalarConverter.cpp

all: $(NAME)

$(NAME): $(SRC) ScalarConverter.hpp Data.hpp
	c++ -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
