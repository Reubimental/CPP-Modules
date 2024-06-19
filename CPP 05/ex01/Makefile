NAME		=	Bureaucrat
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	Bureaucrat.cpp Form.cpp main.cpp
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

re: fclean all

.PHONY: all clean fclean re