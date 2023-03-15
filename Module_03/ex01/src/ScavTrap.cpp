/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 13:47:59 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/15 13:33:10 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20)
{
	std::cout << "Default Constructor called of ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	*this = copy;

	std::cout << "Copy Constructor called of ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "Parameter Constructor called of ScavTrap" << std::endl;
}


// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called of ScavTrap" << std::endl;
}


// Member functions
void	ScavTrap::attack(const std::string& target)
{
	if (!this->_CanTakeAction())
		return ;

	std::cout << "[ATTACK]" << std::endl;
	std::cout << "ScavTrap: " << this->_name << " attacks " << target
			<< ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "[GUARD GATE]" << std::endl;
	std::cout << this->getName() << " guards the gate! No one shall pass.." << std::endl;
}


// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	this->_name = assign._name;
	this->_hit_points = assign._hit_points;
	this->_energy_points = assign._energy_points;
	this->_attack_damage = assign._attack_damage;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const ScavTrap &scavTrap)
{
	out << "ScavTrap object info:" << std::endl;
	out << "---------------------" << std::endl;
	out << "Name:\t\t\t" << scavTrap.getName() << std::endl;
	out << "Current Hit points:\t" << scavTrap.getHitPoints() << std::endl;
	out << "Current Energy:\t\t" << scavTrap.getEnergyPoints() << std::endl;
	out << "Attack Damage:\t\t" << scavTrap.getAttackDamages() << std::endl;
	return out;
}

