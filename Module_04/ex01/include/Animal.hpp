/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 13:40:33 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/21 13:29:46 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);
		Animal(std::string type);

		// Destructor
		virtual ~Animal();

		// Operators
		Animal & operator=(const Animal &assign);

		// Member functions
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
		virtual Brain*	getBrain(void) const = 0;

	protected:
		std::string	type;
};

std::ostream & operator<<(std::ostream &out, const Animal &animal);

#endif
