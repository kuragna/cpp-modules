NAME		=	a.out
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -fr
SRC			=	$(addprefix src/, main.cpp ClapTrap.cpp FragTrap.cpp)
INC			=	$(addprefix include/, ClapTrap.hpp FragTrap.hpp)

all: $(NAME)

$(NAME): $(SRC) $(INC)
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re