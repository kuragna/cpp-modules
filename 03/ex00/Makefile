NAME		=	a.out
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -fr
SRC			=	main.cpp ClapTrap.cpp

all: $(NAME)

$(NAME): $(SRC) ClapTrap.hpp
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re