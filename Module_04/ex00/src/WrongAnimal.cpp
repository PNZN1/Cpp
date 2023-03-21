/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 13:47:39 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/21 10:56:19 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal() : type("")
{
	std::cout << "Default Constructor called of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;

	std::cout << "Copy Constructor called of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Parameter Constructor called of WrongAnimal" << std::endl;
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called of WrongAnimal" << std::endl;
}


// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->type = assign.type;
	return (*this);
}

// Member Functions
std::string	WrongAnimal::getType(void) const {return (this->type);}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Default WrongAnimal sound" << std::endl;
}


std::ostream &operator<<(std::ostream &out, const WrongAnimal &wrongAnimal)
{
	out << wrongAnimal.getType() << std::endl;
	return (out);
}
