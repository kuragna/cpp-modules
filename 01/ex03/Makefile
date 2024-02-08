NAME		=	weapon
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g3
RM			=	rm -fr
SRC			=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
INC			=	Weapon.hpp HumanA.hpp HumanB.hpp

SRC			:=	$(addprefix src/, $(SRC))
INC			:=	$(addprefix include/, $(INC))

all: $(NAME)

$(NAME): $(SRC) $(INC)
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re