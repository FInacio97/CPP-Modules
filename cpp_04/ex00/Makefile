NAME = Animal

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =main.cpp Animal.cpp Dog.cpp Cat.cpp \
		WrongAnimal.cpp WrongCat.cpp

all:$(NAME)
$(NAME):$(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

.PHONY: all fclean