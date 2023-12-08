NAME = megaphone

FLAGS = -Wall -Werror -Wextra -std=c++98

CC	  = c++

RM	  = rm -fr

all: $(NAME)

$(NAME): megaphone.cpp
	$(CC) -o $@ $(FLAGS) $<

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
