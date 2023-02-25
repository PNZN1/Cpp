/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 15:03:20 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 15:16:24 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <HumanB.hpp>
#include <iostream>

HumanB::HumanB(void) {};
HumanB::HumanB(std::string name) : _name(name) {};
HumanB::~HumanB(void) {};


void	HumanB::attack(void)
{
	if (this->_weapon.getType().empty())
		std::cout << this->_name << " doesn't have a weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}
