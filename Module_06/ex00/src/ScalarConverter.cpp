/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 10:42:00 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/28 14:55:15 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor is called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
	std::cout << "Copy constructor is called." << std::endl;
}

ScalarConverter::ScalarConverter(std::string arg)
{
	(void)arg;
	std::cout << "Parameter constructor is called." << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor is called." << std::endl;
}

// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void)assign;
	std::cout << "Assignment operator is called." << std::endl;
	return (*this);
}


// Private functions
void	ScalarConverter::setDecimal(std::string &arg, std::string &decimal)
{
	int		decimalPoint = 0;
	bool	isDecimal = true;
	int		i = 0;

	if (arg.front() == '-')
		i = 1;
	if (arg.back() == 'f')
		arg.pop_back();
	for (; i < arg.c_str()[i]; i++)
	{
		if (arg.c_str()[i] == '.')
			decimalPoint++;
		else if (!isdigit(arg.c_str()[i]))
			throw(InvalidNumber());
		if (arg.c_str()[i] == '.' && static_cast<int>(arg.length())-1 == i)
			throw(InvalidNumber());
		else if (decimalPoint == 1 && arg.c_str()[i] != '.' && arg.c_str()[i] != '0')
			isDecimal = false;
	}
	if (decimalPoint > 1)
		throw(InvalidNumber());
	if (isDecimal)
		decimal = ".0";
}

void	ScalarConverter::convert(std::string arg)
{
	long double	number;
	std::string	decimal = "";
	std::stringstream	ss;

	if (arg.length() == 1 && !isdigit(arg.c_str()[0]))
	{
		decimal = ".0";
		ss << static_cast<int>(arg.c_str()[0]);
	}
	else
	{
		try
		{
			setDecimal(arg, decimal);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what();
			return ;
		}
		ss << arg;
	}
	ss >> number;

	// To char
	if ((number <= 32 && number >= 0) || number == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (number < 0 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(number) << "'" << std::endl;

	// To int
	if (number < -std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(number) << std::endl;

	// To float
	if (number < -std::numeric_limits<float>::max())
		std::cout << "float: -inff" << std::endl;
	else if (number > std::numeric_limits<float>::max())
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(number) << decimal << "f" << std::endl;

	// To double
	if (number < -std::numeric_limits<double>::max())
		std::cout << "double: -inf" << std::endl;
	else if (number > std::numeric_limits<double>::max())
		std::cout << "double: +inf" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(number) << decimal << std::endl;
}


// // Exceptions
const char	*ScalarConverter::InvalidNumber::what() const throw()
{
	return ("char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
}
