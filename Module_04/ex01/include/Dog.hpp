/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 14:12:34 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/21 13:39:45 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		Dog(std::string type);

		// Destructor
		~Dog();

		// Operators
		Dog & operator=(const Dog &assign);

		// Member Functions
		void	makeSound(void) const;
		Brain	*getBrain(void) const;

	private:
		Brain*	brain;
};

std::ostream & operator<<(std::ostream &out, const Dog &dog);

#endif
