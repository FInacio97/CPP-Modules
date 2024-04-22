# include "easyfind.hpp"
# include <list>

int main()
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(12);
    list.push_back(23);
    list.push_back(23);
    list.push_back(30);

    std::list<int>::iterator it;

    for (it = list.begin(); it != list.end(); ++it)
        std::cout << &(*it) << std::endl;
    

    for (int i = 0; i <= 30; i++)
    {
        if (easyfind(list, i))
            std::cout << GREEN << "[" << i << "] exists on the container\n" << RESET;
        else
            std::cout << RED << "[" << i << "] doesn't exist on the container\n" << RESET;
    }
}