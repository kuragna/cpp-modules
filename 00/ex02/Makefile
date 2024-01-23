NAME		=	account
CC			=	g++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -fr
SRC			=	tests.cpp Account.cpp

all: $(NAME)

$(NAME): $(SRC) Account.hpp
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re