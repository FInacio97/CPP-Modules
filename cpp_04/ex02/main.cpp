# include "AAnimal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

// int main()
// {
// 	AAnimal *bobi = new Dog;

// 	bobi->makeSound();
// 	delete (bobi);
// 	bobi = new Cat;
// 	bobi->makeSound();

// 	// AAnimal error;				// not allowed

// 	AAnimal *catto = new Cat;
// 	AAnimal *kitty = new Cat;
// 	kitty = catto;
// }


int	main3()
{
	//Animal	hey;
	Cat		hithere;
	Dog		hello;

	return (0);
}


void	half_cat_half_dog_new_speak_delete(unsigned int number)
{
	AAnimal** everyone = new (std::nothrow) AAnimal* [number];
	unsigned int i;

	for (i = 0; i < number / 2; i++)
		everyone[i] = new (std::nothrow) Cat();
	while (i < number)
		everyone[i++] = new (std::nothrow) Dog();

	for (i = 0; i < number; i++)
		everyone[i]->makeSound();

	for (i = 0; i < number; i++)
		delete everyone[i];

	delete[] everyone;
}



int main()
{
	half_cat_half_dog_new_speak_delete(10);

	return (0);
}

int main1()
{

	// deep copy test

	Cat first;

	first.getBrain()->setIdeas(10, "hello tretas");

	Cat second(first);

	first.getBrain()->setIdeas(10, "haha enganei te");

	std::cout << second.getBrain()->getIdea(10) << std::endl;

	first.makeSound();

	AAnimal* cenas = new Cat();

	delete cenas;

	return (0);
}
