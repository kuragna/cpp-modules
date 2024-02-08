NAME		=	zombie
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98 -fsanitize=address
RM			=	rm -fr
SRC			=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all: $(NAME)

$(NAME): $(SRC) Zombie.hpp
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re