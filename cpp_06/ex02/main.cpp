# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>
# include <ctime>
# include <cstdlib>
# include <exception>
# include <typeinfo>

Base *generate(void)
{
    std::srand(std::time(NULL));
    int ran = rand() % 3;

    switch (ran)
    {
    case 0:
        std::cout << "Generated A\n";
        return (new A);
    
    case 1:
        std::cout << "Generated B\n";
        return (new B);
    
    case 2:
        std::cout << "Generated C\n";
        return (new C);
    }
    return (NULL);
}

void indentify(Base *p)
{
    std::cout << "++++ Identification by pointer ++++\n";
    {
        A *a = dynamic_cast<A *>(p);
        if (a)
        {
            std::cout << "points to an instance of A\n";
            return ;
        }
    }

    {
        B *b = dynamic_cast<B *>(p);
        if (b)
        {
            std::cout << "points to an instance of B\n";
            return ;
        }
    }
    
    {
        C *c = dynamic_cast<C *>(p);
        if (c)
        {
            std::cout << "points to an instance of C\n";
            return ;
        }
    }
}

void indentify(Base &p)
{
    std::cout << "++++ Identification by reference ++++\n";
    try
    {
        A &a = dynamic_cast<A &> (p);
        (void) a;
        std::cout << "points to an instance of A\n";
        return ;
    }
    catch(const std::bad_cast &b)
    {}

    try
    {
        B &b = dynamic_cast<B &> (p);
        (void) b;
        std::cout << "points to an instance of B\n";
        return ;
    }
    catch(const std::bad_cast &b)
    {}

    try
    {
        C &c = dynamic_cast<C &> (p);
        (void) c;
        std::cout << "points to an instance of C\n";
        return ;
    }
    catch(const std::bad_cast &b)
    {}
    
}

int main()
{
    Base *ptr = generate();

    indentify(ptr);
    indentify(*ptr);

    delete ptr;
}