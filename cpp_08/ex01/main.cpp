# include "Span.hpp"

int main()
{
    std::cout << "+++++++ Copy assignment test +++++++++++\n";
    try
    {
        Span a(10);

        a.addRandom(10);

        a.displayArray();

        Span b(a);

        b.displayArray();
    }
    catch (std::exception &e)
    {
        std::cerr << "Error\n";
    }

    std::cout << "\n++++++++ Subjects test +++++++++++\n";

    
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        
    }
 
    std::cout << "\n++++++++ My tests +++++++++++\n";

    try
    {
        Span a(10);
        
        a.addNumber(19);
        a.addNumber(19);
        a.addNumber(15);
        a.addNumber(162);
        a.addNumber(161);
        a.addNumber(12);

        a.displayArray();
        std::cout << "Longest span: " << a.longestSpan() << std::endl;
        std::cout << "Shortest span: " << a.shortestSpan() << "\n\n";
    }
    catch(std::exception &e)
    {
        std::cerr << "Error\n";
    }

    try
    {
        Span a(50);


        a.addRandom(20);
        a.displayArray();
        std::cout << "Longest span: " << a.longestSpan() << std::endl;
        std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error\n";
    }

    std::cout << "\n++++++++ Huge number test +++++++++++\n";

    try
    {
        Span a(10000);


        a.addRandom(10000);
        std::cout << "Longest span: " << a.longestSpan() << std::endl;
        std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error\n";
    }
}  