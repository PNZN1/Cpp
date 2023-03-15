/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 14:15:05 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/15 15:15:46 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog() : Animal("Dog")
{
	std::cout << "Default Constructor called of Dog" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	*this = copy;

	std::cout << "Copy Constructor called of Dog" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Parameter Constructor called of Dog" << std::endl;
}


// Destructor
Dog::~Dog()
{
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


std::ostream &operator<<(std::ostream &out, const Dog &dog)
{
	out << dog.getType() << std::endl;
	return (out);
}
