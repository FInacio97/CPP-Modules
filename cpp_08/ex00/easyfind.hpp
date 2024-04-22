# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <iostream>

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

template <typename T>
bool easyfind(T &container, int n)
{
    typename T::const_iterator result = find(container.begin(), container.end(), n);
    if (result == container.end())
        return(false);
    std::cout << &(*result) << std::endl;
    return(true);
}

# endif