/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 13:47:39 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/02 10:07:28 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors
Animal::Animal() : type("")
{
	std::cout << "Default Constructor called of Animal" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;

	std::cout << "Copy Constructor called of Animal" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Parameter Constructor called of Animal" << std::endl;
}


// Destructor
Animal::~Animal()
{
	std::cout << "Destructor called of Animal" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	this->type = assign.getType();
	return (*this);
}

// Member Functions
std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Default Animal sound" << std::endl;
}


std::ostream &operator<<(std::ostream &out, const Animal &animal)
{
	out << animal.getType() << std::endl;
	return (out);
}
