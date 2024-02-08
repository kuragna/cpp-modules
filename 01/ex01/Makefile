NAME		=	zombie
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -fr
SRC			=	main.cpp Zombie.cpp zombieHorde.cpp

all: $(NAME)

$(NAME): $(SRC) Zombie.hpp
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re