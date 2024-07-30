NAME		= a.out
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
SRC			= main.cpp 

all: $(NAME)

$(NAME): $(SRC) iter.hpp
	c++ -o $@ $(CPPFLAGS) $(SRC)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
