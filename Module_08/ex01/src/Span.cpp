/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 08:41:40 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/02 13:59:47 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

// Constructors
Span::Span() : mN(0)
{
	std::cout << "Default Constructor called of Span" << std::endl;
}

Span::Span(const Span &copy)
{
	std::cout << "Copy Constructor called of Span" << std::endl;
	this->mN = copy.mN;
	this->mIntVector = copy.mIntVector;
	*this = copy;
}

Span::Span(unsigned int N) : mN(N)
{
	std::cout << "Parameter Constructor called of Span" << std::endl;
}

// Destructor
Span::~Span()
{
	std::cout << "Destructor called of Span" << std::endl;
}


// Operators
Span	& Span::operator=(const Span &assign)
{
	this->mN = assign.mN;
	return (*this);
}


// Member functions
void	Span::addNumber(int number)
{
	if(this->mIntVector.size() >= this->mN)
		throw(MaxSize());
	this->mIntVector.push_back(number);
}

void	Span::insertMany(void)
{
	if (this->mN < 2)
		throw(NoSpan());

	std::vector<int>	temp(this->mN, 0);
	srand(time(NULL));
	std::generate_n(temp.begin(), this->mN +1, rand);
	this->mIntVector.insert(this->mIntVector.begin(), temp.begin(), temp.end());
}

unsigned int	Span::shortestSpan(void)
{
	if (this->mIntVector.size() < 2)
		throw(NoSpan());

	std::vector<int>	temp = this->mIntVector;
	std::sort(temp.begin(), temp.end());
	int	span = std::numeric_limits<int>::max();

	std::vector<int>::iterator	i = temp.begin() + 1;
	for(; i != temp.end(); i++)
	{
		if(*i - *(i - 1) < span)
			span = *i - *(i - 1);
	}
	return (static_cast<unsigned int>(span));
}

unsigned int	Span::longestSpan(void)
{
	if (this->mIntVector.size() < 2)
		throw(NoSpan());

	std::vector<int>::iterator	first = this->mIntVector.begin();
	std::vector<int>::iterator	last = this->mIntVector.end();

	return (static_cast<unsigned int>(*std::max_element(first, last) - *std::min_element(first, last)));
}

std::vector<int>	Span::getVector(void) const
{
	return (this->mIntVector);
}

// Exceptions
const char	*Span::MaxSize::what() const throw()
{
	return ("The maximum size is reached, you cannot add any numbers.");
}

const char	*Span::NoSpan::what() const throw()
{
	return ("Could not find any span.");
}
