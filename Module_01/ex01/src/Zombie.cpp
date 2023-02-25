/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 12:30:30 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 13:30:23 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <iostream>

Zombie::Zombie(void) {}


Zombie::Zombie(std::string name) : _name(name) {}


Zombie::~Zombie(void)
{
	std::cout << this->_name << " destroyed!" << std::endl;
	return ;
}


void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


void	Zombie::setName(std::string name)
{
	this->_name = name;
}
