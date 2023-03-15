/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 14:12:34 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/15 15:09:27 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
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
};

std::ostream & operator<<(std::ostream &out, const Cat &cat);

#endif
