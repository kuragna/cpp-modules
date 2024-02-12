NAME		=	a.out
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -fr
SRC			=	$(addprefix src/, main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp)
INC			=	$(addprefix include/, Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp)

all: $(NAME)

$(NAME): $(SRC) $(INC)
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re