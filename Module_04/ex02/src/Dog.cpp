/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 14:15:05 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/29 09:34:19 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog() : AAnimal("Dog")
{
	this->brain = new Brain();
	std::cout << "Default Constructor called of Dog" << std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal("Dog")
{
	*this = copy;

	std::cout << "Copy Constructor called of Dog" << std::endl;
}

Dog::Dog(std::string type) : AAnimal(type)
{
	std::cout << "Parameter Constructor called of Dog" << std::endl;
}


// Destructor
Dog::~Dog()
{
	delete this->brain;
	std::cout << "Destructor called of Dog" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->type = assign.getType();
	return (*this);
}

// Member Functions
void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof!!" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (this->brain);
}

std::ostream &operator<<(std::ostream &out, const Dog &dog)
{
	out << dog.getType() << std::endl;
	return (out);
}
