#include <iostream>
#include "Array.hpp"
# include <ctime>
# include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    {
        std::cout << "+++++ My TESTS +++++\n";

        std::cout << "Deep copy: \n";

        Array<int> a(23);
        {
            a[2] = 1;
            Array<int> b(a);
            std::cout << b[2] << std::endl;
        }
        std::cout << a[2] << std::endl;

        std::cout << "Const test: \n";

        const Array<int> c(3);
        std::cout << a[0] << std::endl;

        std::cout << "size of c: " << c.size() << std::endl;
    }

    {
        std::cout << "\n+++++ 42s TEST +++++\n";
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
        return 0;
    }


}