# include "easyfind.hpp"
# include <list>
# include <vector>

int main()
{

    {
        std::cout << YELLOW << "+++++++++++++++ Test with list +++++++++++++++++\n" << RESET;

        std::list<int> list;

        list.push_back(1);
        list.push_back(12);
        list.push_back(23);
        list.push_back(23);
        list.push_back(30);

        std::list<int>::iterator it;

        for (it = list.begin(); it != list.end(); ++it)
            std::cout << CYAN << *it << ": " << &(*it) << std::endl;
        

        for (int i = 0; i <= 35; i++)
        {
            if (easyfind(list, i))
                std::cout << GREEN << "[" << i << "] exists on the container\n" << RESET;
            else
                std::cout << RED << "[" << i << "] doesn't exist on the container\n" << RESET;
        }
    }

    {
        std::cout << YELLOW << "+++++++++++++++ Test with vectors +++++++++++++++++\n" << RESET;

        std::vector<int> vec;

        vec.push_back(1);
        vec.push_back(12);
        vec.push_back(23);
        vec.push_back(23);
        vec.push_back(30);

        std::vector<int>::iterator it;

        for (it = vec.begin(); it != vec.end(); ++it)
            std::cout << CYAN << *it << ": " << &(*it) << std::endl;
        

        for (int i = 0; i <= 35; i++)
        {
            if (easyfind(vec, i))
                std::cout << GREEN << "'" << i << "' exists on the container\n" << RESET;
            else
                std::cout << RED << "'" << i << "' doesn't exist on the container\n" << RESET;
        }
    }
}