NAME		=	a.out
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98 -Wshadow
RM			=	rm -fr
SRC			=	$(addprefix src/, main.cpp DiamondTrap.cpp ScavTrap.cpp ClapTrap.cpp FragTrap.cpp)
INC			=	$(addprefix include/, DiamondTrap.hpp ScavTrap.hpp ClapTrap.hpp FragTrap.hpp)


all: $(NAME)

$(NAME): $(SRC) $(INC)
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re