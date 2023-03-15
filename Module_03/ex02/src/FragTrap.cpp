/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 13:47:59 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/15 13:27:42 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap("", 100, 100, 30)
{
	std::cout << "Default Constructor called of FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;

	std::cout << "Copy Constructor called of FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "Parameter Constructor called of FragTrap" << std::endl;
}


// Destructor
FragTrap::~FragTrap()
{
	std::cout << "Destructor called of FragTrap" << std::endl;
}


// Member functions
void	FragTrap::highFivesGuys(void)
{
	std::cout << "[HIGH FIVE GUYS]" << std::endl;
	std::cout << this->getName() << " requested a positive high five. It is given.." << std::endl;
}


// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	this->_name = assign._name;
	this->_hit_points = assign._hit_points;
	this->_energy_points = assign._energy_points;
	this->_attack_damage = assign._attack_damage;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const FragTrap &fragTrap)
{
	out << "FragTrap object info:" << std::endl;
	out << "---------------------" << std::endl;
	out << "Name:\t\t\t" << fragTrap.getName() << std::endl;
	out << "Current Hit points:\t" << fragTrap.getHitPoints() << std::endl;
	out << "Current Energy:\t\t" << fragTrap.getEnergyPoints() << std::endl;
	out << "Attack Damage:\t\t" << fragTrap.getAttackDamages() << std::endl;
	return out;
}
