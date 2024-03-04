# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"


// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();

//     delete j;//should not create a leak
//     delete i;

//     std::cout << " ========= || My test || ========= " << std::endl;

//     Animal *farm[6];

//     for (int i = 0; i < 6; i++)
//     {
//         if (i % 2 == 0)
//             farm[i] = new Cat();
//         else
//             farm[i] = new Dog();
//     }
//     for (int j = 0; j < 6; j++)
//         delete farm[j];
//     return 0;
// }

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
    }

    std::cout << "\n*********** My tests ***********\n" << std::endl;

    Animal *beast = new Dog();
    
    // for (int x = 0; x < 101; x++)
    //     beast->getBrain()->setIdea(x, "Thinks in the language of dogs...");

    Animal *copy = new Dog(static_cast<Dog&>(*beast));

    // std::cout << std::endl;
    // try 
    // {
    //     for (int x = 0; x < 101; x++)
    //         std::cout << copy->getBrain()->getIdea(x) << std::endl;
    // } 
    // catch(std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    // delete beast;
    // delete copy;

    // return 0;
}

// void	half_cat_half_dog_new_speak_delete(unsigned int number)
// {
// 	Animal** everyone = new (std::nothrow) Animal* [number];
// 	unsigned int i;

// 	for (i = 0; i < number / 2; i++)
// 		everyone[i] = new (std::nothrow) Cat();
// 	while (i < number)
// 		everyone[i++] = new (std::nothrow) Dog();

// 	for (i = 0; i < number; i++)
// 		everyone[i]->makeSound();

// 	for (i = 0; i < number; i++)
// 		delete everyone[i];

// 	delete[] everyone;
// }

// int main1()
// {
// 	half_cat_half_dog_new_speak_delete(10);

// 	return (0);
// }

// int main4()
// {

// 	// deep copy test

// 	Dog first;

// 	first.getBrain()->setIdeas(10, "hello tretas");

// 	Dog second(first);


// 	first.getBrain()->setIdeas(10, "haha enganei te");

// 	// std::cout << first.getBrain()->getIdea(10) << std::endl;
// 	std::cout << second.getBrain()->getIdea(10) << std::endl;

// 	return (0);
// }


// int main3()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete i;
// 	delete j;

// 	return (0);
// }


// int main()
// {
// 	Animal	ani;
// 	Cat		queni;
// 	Dog		cati;

// 	ani.makeSound();
// 	queni.makeSound();
// 	cati.makeSound();

// 	return (0);
// }