NAME	= phonebook
CC		= g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = main.cpp Phonebook.cpp Contact.cpp
OBJ	= $(patsubst %.cpp, %.o, $(SRC))
RM	= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re