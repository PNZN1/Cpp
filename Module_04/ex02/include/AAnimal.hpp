/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 13:40:33 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/02 10:05:38 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal
{
	public:
		// Constructors
		AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal(std::string type);

		// Destructor
		virtual ~AAnimal();

		// Operators
		AAnimal & operator=(const AAnimal &assign);

		// Member functions
		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;

	protected:
		std::string	type;
};

std::ostream & operator<<(std::ostream &out, const AAnimal &aanimal);

#endif
