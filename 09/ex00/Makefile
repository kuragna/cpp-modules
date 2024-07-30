NAME		= btc
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
SRC			= main.cpp BitcoinExchange.cpp
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	c++ -c $(CPPFLAGS) $< -o $@

$(NAME): $(OBJ)
	c++ -o $@ $(CPPFLAGS) $(OBJ)

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re clean
