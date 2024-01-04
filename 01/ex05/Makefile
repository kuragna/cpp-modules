NAME		=	harl

CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -fr

SRC			=	main.cpp Harl.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -o $@ $(CPPFLAGS) $^

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re