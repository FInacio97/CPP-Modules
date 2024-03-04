NAME = materia

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =main.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp \
		MateriaSource.cpp

all:$(NAME)
$(NAME):$(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

.PHONY: all fclean