/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 14:15:05 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/29 09:34:15 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat() : AAnimal("Cat")
{
	this->brain = new Brain();
	std::cout << "Default Constructor called of Cat" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal("Cat")
{
	*this = copy;

	std::cout << "Copy Constructor called of Cat" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type)
{
	std::cout << "Parameter Constructor called of Cat" << std::endl;
}


// Destructor
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Destructor called of Cat" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->type = assign.getType();
	this->brain = new Brain(*assign.getBrain());
	return (*this);
}

// Member Functions
void	Cat::makeSound(void) const
{
	std::cout << "Miauw Miauw!!" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return (this->brain);
}


std::ostream &operator<<(std::ostream &out, const Cat &cat)
{
	out << cat.getType() << std::endl;
	return (out);
}
