NAME		=	Bureaucrat
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

TREES		=	$(shell find . -name '*_shrubbery')

SRC			=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJ			=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	@$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@if [ -f "$(TREES)" ]; then \
	$(RM) $(TREES); \
	fi;

re: fclean all

.PHONY: all clean fclean re