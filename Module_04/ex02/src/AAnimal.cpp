/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 13:47:39 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/02 10:06:56 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors
AAnimal::AAnimal() : type("")
{
	std::cout << "Default Constructor called of AAnimal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	*this = copy;

	std::cout << "Copy Constructor called of AAnimal" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "Parameter Constructor called of AAnimal" << std::endl;
}


// Destructor
AAnimal::~AAnimal()
{
	std::cout << "Destructor called of AAnimal" << std::endl;
}


// Operators
AAnimal & AAnimal::operator=(const AAnimal &assign)
{
	this->type = assign.getType();
	return (*this);
}

// Member Functions
std::string	AAnimal::getType(void) const
{
	return (this->type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Default AAnimal sound" << std::endl;
}


std::ostream &operator<<(std::ostream &out, const AAnimal &aanimal)
{
	out << aanimal.getType() << std::endl;
	return (out);
}
