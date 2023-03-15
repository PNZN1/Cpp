/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 08:15:37 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/13 14:28:42 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		// Constructors
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage);

		// Destructor
		~ClapTrap();

		// Operators
		ClapTrap & operator=(const ClapTrap &assign);

		// Member functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// Getters
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamages(void) const;

	protected:

		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

		bool			_CanTakeAction(void) const;
};

std::ostream & operator<<(std::ostream &out, const ClapTrap &claptrap);

#endif
