NAME		= PmergeMe
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 -ggdb
SRC			= main.cpp PmergeMe.cpp

all: $(NAME)

$(NAME): $(SRC)
	c++ -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
