/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 14:47:11 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 15:07:05 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <Weapon.hpp>
# include <string>

class	HumanB
{
	private:
		std::string	_name;
		Weapon		_weapon;

	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon weapon);
};

#endif
