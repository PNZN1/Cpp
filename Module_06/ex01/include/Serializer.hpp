/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:56:32 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 10:19:35 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

class Serializer
{
	private:
		// Constructors
		Serializer();
		Serializer(const Serializer &copy);

		// Destructor
		~Serializer();

		// Operators
		Serializer & operator=(const Serializer &assign);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data		*deserialize(uintptr_t raw);
};

#endif
