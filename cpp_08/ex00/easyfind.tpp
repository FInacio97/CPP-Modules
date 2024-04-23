# include "easyfind.hpp"

template <typename T>
bool easyfind(T const &container, const int n)
{
    typename T::const_iterator result = std::find(container.begin(), container.end(), n);
    if (result == container.end())
        return(false);
    std::cout << &(*result) << std::endl;
    return(true);
}