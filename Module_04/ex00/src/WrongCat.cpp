/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 14:15:05 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/21 11:00:25 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default Constructor called of WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;

	std::cout << "Copy Constructor called of WrongCat" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "Parameter Constructor called of WrongCat" << std::endl;
}


// Destructor
WrongCat::~WrongCat()
{
	std::cout << "Destructor called of WrongCat" << std::endl;
}


// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	this->type = assign.getType();
	return (*this);
}

// Member Functions
void	WrongCat::makeSound(void) const
{
	std::cout << "Miauw Miauw!!" << std::endl;
}


std::ostream &operator<<(std::ostream &out, const WrongCat &wrongCat)
{
	out << wrongCat.getType() << std::endl;
	return (out);
}
