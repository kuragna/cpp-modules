NAME = megaphone
FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address
CPP   = c++
RM	  = rm -fr

all: $(NAME)

$(NAME): megaphone.cpp
	$(CPP) -o $@ $(FLAGS) $<

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
