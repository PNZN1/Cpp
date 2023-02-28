/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 10:30:02 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/28 15:29:58 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <cmath>

// Constructors
Fixed::Fixed(void) : _fpoint(0) {}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int number)
{
	this->setRawBits(number << this->_fbits);
}

Fixed::Fixed(const float number)
{
	this->_fpoint = roundf(number * (1 << this->_fbits));
}


// Destructor
Fixed::~Fixed(void) {}


// Operators
Fixed & Fixed::operator=(const Fixed & rhs)
{
	this->setRawBits(rhs.getRawBits());
	return (*this);
}


// arithmetic operators: +, -, *, and /
Fixed	Fixed::operator+(const Fixed & rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed & rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed & rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed & rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}


// comparison operators: >, <, >=, <=, == and !=
int	Fixed::operator>(const Fixed & rhs) const {return (this->toFloat() > rhs.toFloat());}
int	Fixed::operator<(const Fixed & rhs) const {return (this->toFloat() < rhs.toFloat());}
int	Fixed::operator>=(const Fixed & rhs) const {return (this->toFloat() >= rhs.toFloat());}
int	Fixed::operator<=(const Fixed & rhs) const {return (this->toFloat() <= rhs.toFloat());}
int	Fixed::operator==(const Fixed & rhs) const {return (this->toFloat() == rhs.toFloat());}
int	Fixed::operator!=(const Fixed & rhs) const {return (this->toFloat() != rhs.toFloat());}


// post/pre increment/decrement
Fixed	Fixed::operator++(int)
{
	Fixed	post_increment;

	post_increment = *this;
	*this = *this + 1;
	return (post_increment);
}

Fixed	Fixed::operator++()
{
	*this = *this + 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	post_increment;

	post_increment = *this;
	*this = *this - 1;
	return (post_increment);
}

Fixed	Fixed::operator--()
{
	*this = *this - 1;
	return (*this);
}


std::ostream & operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}


// min/max
Fixed	Fixed::min(Fixed & a,  Fixed & b) {return ((a < b) ? a : b);}
Fixed	Fixed::max(Fixed & a,  Fixed & b) {return ((a > b) ? a : b);}
Fixed	Fixed::min(const Fixed & a, const Fixed & b) {return ((a < b) ? a : b);}
Fixed	Fixed::max(const Fixed & a, const Fixed & b) {return ((a > b) ? a : b);}


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
