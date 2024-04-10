# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << "\n*********** My tests ***********\n" << std::endl;

    Animal *animals[10];
    
    int x = 0;
    for (x = 0; x < 5; x++)
        animals[x] = new Dog();
    for ( ; x < 10; x++)
        animals[x] = new Cat();
    for (int k = 0; k < 10; k++)
        animals[k]->makeSound();
    for (int k = 0; k < 10; k++)
        delete animals[k];

    std::cout << "\n***** Copy and assignment tests *****\n" << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
        std::cout << tmp.getBrain() << std::endl;
        std::cout << basic.getBrain() << std::endl;
    }
}