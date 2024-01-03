NAME		=	zombie

CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra
RM			=	rm -fr

SRC			=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -o $@ $(CPPFLAGS) $^

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re