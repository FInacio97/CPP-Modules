# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
    std::cout << YELLOW << "TEST ONE: Everything works as expected" << std::endl;
    try
    {
        Form yolo("yolo", 5, 3);
        Bureaucrat Arminda("Arminda", 4);

        std::cout << yolo;
        Arminda.signForm(yolo);
        std::cout << yolo;
        Arminda.signForm(yolo);
        std::cout << yolo;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << YELLOW << "TEST TWO: Bureaucrat's grade is too low" << std::endl;
    try
    {
        Form yolo("yolo", 10, 3);
        Bureaucrat Arminda("Arminda", 40);

        std::cout << yolo;
        Arminda.signForm(yolo);
        std::cout << yolo;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << YELLOW << "TEST THREE: Form grade out of bounds" << RESET << std::endl;

     try
    {
        Form yolo("yolo", 160, 3);
        Bureaucrat Arminda("Arminda", 4);

        std::cout << yolo;
        Arminda.signForm(yolo);
        std::cout << yolo;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form yolo("yolo", 0, 3);
        Bureaucrat Arminda("Arminda", 4);

        std::cout << yolo;
        Arminda.signForm(yolo);
        std::cout << yolo;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form yolo("yolo", 12, -3);
        Bureaucrat Arminda("Arminda", 4);

        std::cout << yolo;
        Arminda.signForm(yolo);
        std::cout << yolo;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form yolo("yolo", 12, 183);
        Bureaucrat Arminda("Arminda", 4);

        std::cout << yolo;
        Arminda.signForm(yolo);
        std::cout << yolo;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}