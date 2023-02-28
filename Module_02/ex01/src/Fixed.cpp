/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 10:30:02 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/28 11:01:36 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <cmath>

// Constructors
Fixed::Fixed(void) : _fpoint(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(number << this->_fbits);
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpoint = roundf(number * (1 << this->_fbits));
}


// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	(void) assign;

	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(assign.getRawBits());
	return (*this);
}

std::ostream & operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}


// Member Functions
int	Fixed::getRawBits(void) const
{
	return (this->_fpoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpoint = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->_fpoint / (1 << this->_fbits));
}

int		Fixed::toInt(void) const
{
	return (this->_fpoint >> this->_fbits);
}
