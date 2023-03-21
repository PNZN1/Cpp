/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:09:25 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/21 14:45:35 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal*	animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Cat();
		else if (i >= 2)
			animals[i] = new Dog();
	}
	std::cout << std::endl;
	animals[0]->getBrain()->setIdea(0, "Wrinting code.");
	std::cout << animals[0]->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	for (int j = 0; j < 4; j++)
		delete animals[j];

	std::cout << std::endl;
	system("leaks -q fire");
	return (0);
}
