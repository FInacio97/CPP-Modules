# include "iter.hpp"

void func(int n)
{
    std::cout << "value: " << n << std::endl;
}

int main()
{
    int n[5] = {0, 1, 2, 3, 4};

    iter(n, 5, func);

	return 0;
}