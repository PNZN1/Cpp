/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 13:55:35 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/21 11:05:51 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_cat = new WrongCat();

	std::cout << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	cat->makeSound(); // will output the cat sound
	dog->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << w_cat->getType() << std::endl;
	w_cat->makeSound(); // will output the default sound
	w_meta->makeSound();

	std::cout << std::endl;
	system("leaks -q poly");
	return (0);
}
