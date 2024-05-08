NAME		= a.out
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 -ggdb #-fsanitize=address
SRC			= main.cpp Span.cpp

all: $(NAME)

$(NAME): $(SRC) Span.hpp
	c++ -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
