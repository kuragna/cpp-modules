NAME		= a.out
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 -fsanitize=address -ggdb
SRC			= main.cpp 

all: $(NAME)

$(NAME): $(SRC) Array.hpp
	c++ -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
