NAME		=	account

CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra
RM			=	rm -fr

SRC			=	tests.cpp account.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -o $@ $(CPPFLAGS) $^

fclean:
	$(RM) $(NAME)
re: fclean all

.PHONY: all fclean re