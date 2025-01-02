NAME = megaphone

SRCS = ./srcs/

CPPFILES = $(SRCS)megaphone.cpp
OFILES = $(CPPFILES:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) -g -o $(NAME) $(OFILES)

$(SRCS)%.o: $(SRCS)%.cpp
	$(CC) $(FLAGS) -g -c -o $@ $<

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re