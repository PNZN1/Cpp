/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 14:02:58 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 15:15:24 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>

Weapon::Weapon(void) {};
Weapon::Weapon(std::string type) : _type(type) {};
Weapon::~Weapon(void) {};


const std::string	Weapon::getType(void)
{
	return (this->_type);
}


void	Weapon::setType(std::string setType)
{
	this->_type = setType;
}
