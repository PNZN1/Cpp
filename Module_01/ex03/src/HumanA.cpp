/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Humana.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 14:52:32 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 15:01:07 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <HumanA.hpp>
#include <iostream>

HumanA::HumanA(void) {};
HumanA::HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon) {};
HumanA::~HumanA(void) {};


void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
