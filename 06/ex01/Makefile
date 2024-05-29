NAME		= a.out
CPPFLAGS	= -std=c++98 -fsanitize=address -Wall -Werror -Wextra
SRC			= main.cpp

all: $(NAME)

$(NAME): $(SRC)
	c++ -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
