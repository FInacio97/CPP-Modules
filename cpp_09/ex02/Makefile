NAME = PmergeMe

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address

SRCS = main.cpp PmergeMe.cpp

OBJS := $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:$(NAME)
$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re