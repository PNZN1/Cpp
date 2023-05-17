/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:25:34 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/17 11:21:04 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

// Constuctors
RPN::RPN() {};

RPN::RPN(const RPN &copy)
{
	this->_numbers = copy._numbers;
}

RPN & RPN::operator=(const RPN &assign)
{
	this->_numbers = assign._numbers;
	return (*this);
}

// Destructor
RPN::~RPN() {};


void	RPN::pushNumber(int num)
{
	this->_numbers.push_back(num);
}

void	RPN::operation(char c)
{
	size_t	size = this->_numbers.size();
	if (size < 2)
		throw(std::invalid_argument("Error"));

	if (c == '+')
		this->_numbers.push_front(this->getIndex(size - 2) + this->getIndex(size - 1));
	else if (c == '-')
		this->_numbers.push_front(this->getIndex(size - 2) - this->getIndex(size - 1));
	else if (c == '*')
		this->_numbers.push_front(this->getIndex(size - 2) * this->getIndex(size - 1));
	else if (c == '/')
		this->_numbers.push_front(this->getIndex(size - 2) / this->getIndex(size - 1));
	else
		throw(std::invalid_argument("Error"));
	this->_numbers.pop_back();
	this->_numbers.pop_back();
}

int	RPN::getIndex(size_t i)
{
	std::list<int>::iterator	it = this->_numbers.begin();

	for (size_t j = 0; j < i; j++)
		it++;
	return (*it);
}

int	RPN::getResult() const
{
	if (this->_numbers.size() != 1)
		throw(std::invalid_argument("Error"));
	return (this->_numbers.front());
}

// Insertion overload
std::ostream &operator<<(std::ostream &out, const RPN &rpn)
{
	out << rpn.getResult();
	return (out);
}
