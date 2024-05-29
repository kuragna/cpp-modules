NAME		= a.out
CPPFLAGS	= -std=c++98  -Wall -Werror -Wextra #-fsanitize=address
SRC			= main.cpp

all: $(NAME)

$(NAME): $(SRC)
	c++ -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
