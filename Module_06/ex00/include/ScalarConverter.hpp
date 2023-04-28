/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 10:27:25 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/28 14:49:38 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>

class ScalarConverter
{
	private:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter(std::string arg);
		// Destructor
		~ScalarConverter();
		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);

		// Private functions
		static void		setDecimal(std::string &arg, std::string &decimal);

		class InvalidNumber : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	public:
		static void		convert(std::string arg);
};

#endif
