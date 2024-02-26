NAME = file_stream

CXX = c++

CXXFLAGS = -std=c++98  -Wall -Wextra -Werror -g

SRCS =main.cpp Harl.cpp

all:$(NAME)
$(NAME):$(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

.PHONY: all fclean