# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;

    std::cout << " ========= || My test || ========= " << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongJ = new WrongCat();
    std::cout << wrongJ->getType() << " " << std::endl;
    wrongJ->makeSound();
    wrongMeta->makeSound();

    Dog basic;
    {
        Dog tmp = basic;
    }

    std::cout << "\n==================\n";
    delete wrongJ;
    std::cout << "==================\n";
    delete wrongMeta;

    return 0;
}