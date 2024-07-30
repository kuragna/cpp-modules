NAME		=	a.out
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra #-std=c++98
RM			=	rm -fr
SRC			=	main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(SRC) Fixed.hpp
	$(CC) -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re