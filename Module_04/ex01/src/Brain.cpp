/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:25:42 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/21 14:05:29 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "Default Constructor called of Brain" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;

	std::cout << "Copy Constructor called of Brain" << std::endl;
}

// Destructor
Brain::~Brain()
{
	std::cout << "Destructor called of Brain" << std::endl;
}


// Operators
Brain & Brain::operator=(const Brain &assign)
{
	(void)assign;
	return (*this);
}


// Member Functions
std::string	Brain::getIdea(int index) const
{
	std::cout << "getIdea of brain is called." << std::endl;
	if (index < 0 || index > 99)
		return ("");
	return (this->ideas[index]);
}

void	Brain::setIdea(int index, std::string idea)
{
	std::cout << "setIdea of brain is called." << std::endl;
	if (index < 0 || index > 99)
		return ;
	this->ideas[index] = idea;
}
