/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 13:42:43 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/15 13:15:51 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Constructors
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);

		// Destructor
		~FragTrap();

		// Operators
		FragTrap & operator=(const FragTrap &assign);

		// Member functions
		void	highFivesGuys(void);
};


std::ostream & operator<<(std::ostream &out, const FragTrap &fragtrap);

#endif
