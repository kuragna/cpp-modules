NAME		=	a.out
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -fr
SRC			=	main.cpp ClapTrap.cpp ScavTrap.cpp
INC			=	ClapTrap.hpp ScavTrap.hpp	

SRC			:=	$(addprefix src/, $(SRC))
INC			:=	$(addprefix include/, $(INC))

all: $(NAME)

$(NAME): $(SRC) $(INC)
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re