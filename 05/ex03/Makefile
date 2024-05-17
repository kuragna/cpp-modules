NAME		= a.out
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 -ggdb
SRC			= main.cpp \
			  Bureaucrat.cpp \
			  AForm.cpp \
			  ShrubberyCreationForm.cpp \
			  RobotomyRequestForm.cpp \
			  PresidentialPardonForm.cpp \
			  Intern.cpp
INC			= Bureaucrat.hpp \
			  AForm.hpp \
			  ShrubberyCreationForm.hpp \
			  RobotomyRequestForm.hpp \
			  PresidentialPardonForm.hpp \
			  Intern.hpp

all: $(NAME)

$(NAME): $(SRC) $(INC)
	g++ -o $@ $(CPPFLAGS) $(filter %.cpp, $^)

fclean:
	rm -fr $(NAME)

re: fclean all

.PHONY: all fclean re
