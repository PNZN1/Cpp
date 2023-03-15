/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 14:15:05 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/15 15:15:28 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Constructor called of Cat" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;

	std::cout << "Copy Constructor called of Cat" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Parameter Constructor called of Cat" << std::endl;
}


// Destructor
Cat::~Cat()
{
	std::cout << "Destructor called of Cat" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->type = assign.getType();
	return (*this);
}

// Member Functions
void	Cat::makeSound(void) const
{
	std::cout << "Miauw Miauw!!" << std::endl;
}


std::ostream &operator<<(std::ostream &out, const Cat &cat)
{
	out << cat.getType() << std::endl;
	return (out);
}
