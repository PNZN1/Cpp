/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 09:20:49 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 10:20:37 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

// Constructors
Serializer::Serializer()
{
	std::cout << "Default Constructor called of Serializer" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	(void)copy;
	std::cout << "Copy Constructor called of Serialzer" << std::endl;
}

// Destructor
Serializer::~Serializer()
{
	std::cout << "Destructor called of Serializer" << std::endl;
}

// Operators
Serializer & Serializer::operator=(const Serializer &assign)
{
	(void)assign;
	return (*this);
}


uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
