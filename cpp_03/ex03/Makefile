NAME = DiamondTrap

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

all:$(NAME)
$(NAME):$(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

.PHONY: all fclean