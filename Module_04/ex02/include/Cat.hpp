/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 14:12:34 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/29 09:33:44 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		Cat(std::string type);

		// Destructor
		~Cat();

		// Operators
		Cat & operator=(const Cat &assign);

		// Member Functions
		void	makeSound(void) const;
		Brain	*getBrain(void) const;

	private:
		Brain*	brain;
};

std::ostream & operator<<(std::ostream &out, const Cat &cat);

#endif
