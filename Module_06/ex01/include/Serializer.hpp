/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:56:32 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/24 14:57:06 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <sstream>

class Serializer
{
	public:
		// Constructors
		Serializer();
		Serializer(const Serializer &copy);
		Serializer(std::string arg);
		// Destructor
		~Serializer();
		// Operators
		Serializer & operator=(const Serializer &assign);

		class InvalidNumber : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

#endif
