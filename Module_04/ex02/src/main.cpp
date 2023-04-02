/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:09:25 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/02 10:11:40 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// this should now be impossible:
	// const AAnimal* nope = new AAnimal();
	AAnimal*	animals[4];
	int			nrAnimals = 4;

	for (int i = 0; i < nrAnimals; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << std::endl;

	std::cout << "========= types =========" << std::endl;
	for (int i = 0; i < nrAnimals; i++)
		std::cout << animals[i]->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "========= sounds =========" << std::endl;
	for (int i = 0; i < nrAnimals; i++)
		animals[i]->makeSound();
	std::cout << std::endl;

	std::cout << "======== destruct =======" << std::endl;
	for (int i = 0; i < nrAnimals; i++)
	{
		std::cout << "animal[" << i << "]:" <<std::endl;
		delete animals[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "====== dog copy test ====" << std::endl;
	const Dog* firstDog = new Dog();
	std::cout << std::endl;
	//setting a thought to check if the value gets copied
	firstDog->getBrain()->setIdea(0, "Dog wants play!");
	std::cout << "firstDog: idea[0] = " << firstDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "firstDog: brain address = " << firstDog->getBrain() << std::endl << std::endl;
	//copying the firstDog to copyDog
	std::cout << "Deep copying the firstDog:" << std::endl;
	const Dog* copyDog = new Dog(*firstDog);
	std::cout << std::endl;
	std::cout << "copyDog: idea[0] = " << copyDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "copyDog: brain address = " << copyDog->getBrain() << std::endl;

	std::cout << "====== cat copy test ====" << std::endl;
	const Cat* firstCat = new Cat();
	std::cout << std::endl;
	firstCat->getBrain()->setIdea(0, "Cat wants murder!");
	std::cout	<< "firstCat: idea[0] = "
				<< firstCat->getBrain()->getIdea(0)
				<< std::endl
				<< "firstCat: brain address = "
				<< firstCat->getBrain()
				<< std::endl << std::endl;
	//copying the firstCat to copyCat
	std::cout << "Deep copying the firstCat:" << std::endl;
	const Cat* copyCat = new Cat(*firstCat);
	std::cout << std::endl;
	std::cout	<< "copyCat: idea[0] = "
				<< copyCat->getBrain()->getIdea(0)
				<< std::endl
				<< "copyCat: brain address = "
				<< copyCat->getBrain()
				<< std::endl << std::endl;

	std::cout << "======== destruct =======" << std::endl;
	delete firstDog;
	delete copyDog;
	delete firstCat;
	delete copyCat;
	std::cout << std::endl;

	std::cout << "======== leak check =======" << std::endl;
	std::cout << std::endl;
	system("leaks -q abc");
	return (0);
}
