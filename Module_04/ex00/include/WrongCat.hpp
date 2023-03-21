/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 14:12:34 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/21 10:59:39 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors
		WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat(std::string type);

		// Destructor
		~WrongCat();

		// Operators
		WrongCat & operator=(const WrongCat &assign);

		// Member Functions
		void	makeSound(void) const;
};

std::ostream & operator<<(std::ostream &out, const WrongCat &wrongCat);

#endif
