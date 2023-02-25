/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Humana.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 14:47:11 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 15:06:52 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <Weapon.hpp>
# include <string>

class	HumanA
{
	private:
		std::string	_name;
		Weapon		_weapon;

	public:
		HumanA(void);
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);

		void	attack(void);
};

#endif
