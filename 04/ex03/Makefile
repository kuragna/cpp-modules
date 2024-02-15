NAME		=	a.out
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98 #-fsanitize=address
RM			=	rm -fr
SRC			=	main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
INC			=	AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp

SRC			:= $(addprefix src/, $(SRC))
INC			:= $(addprefix include/, $(INC))

all: $(NAME)

$(NAME): $(SRC) $(INC)
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re