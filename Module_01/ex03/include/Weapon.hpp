/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 13:58:09 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 14:32:00 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		const std::string	getType(void);
		void				setType(std::string newType);
};

#endif
