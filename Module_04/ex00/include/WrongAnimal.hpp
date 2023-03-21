/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 13:40:33 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/21 11:03:16 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal(std::string type);

		// Destructor
		~WrongAnimal();

		// Operators
		WrongAnimal & operator=(const WrongAnimal &assign);

		// Member functions
		std::string	getType(void) const;
		void	makeSound(void) const;

	protected:
		std::string	type;
};

std::ostream & operator<<(std::ostream &out, const WrongAnimal &wrongAnimal);

#endif
