/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 10:32:58 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 12:00:49 by pniezen       ########   odam.nl         */
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
