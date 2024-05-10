NAME = Array

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = main.cpp

all:$(NAME)
$(NAME):$(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

TODO: CLEAN IS MISSING!

.PHONY: all fclean re